# ctemplate.py

import sys
import datetime


class ctemplate:

    __fileName = ' '
    __sourceName = ' '
    __headerName = ' '
    __time = datetime.datetime.now().strftime('%Y.%m.%d')
    __fileComments = {'@attention':'COPYRIGHT WEYNE',
                      '@note':' ',
                      '@brief':' ',
                      '@date':__time,
                      '@version':'V01',
                      '@author':'Weyne Chen',
                      '@file':" ",
    }

    __CommentsOrder = ('@file','@author','@version','@date','@brief','@note','@attention')

    def __init__(self,s):
        self.__fileName = s
        self.__sourceName = s + ".c"
        self.__headerName = s + '.h'

    def generateCommentsAtTop(self,name):
        self.__fileComments['@file'] = name

        comments = ('/**\n')

        #find max length of string
        maxLen = 0
        for s in self.__CommentsOrder:
            if(len(s) > maxLen):
                maxLen = len(s)

        for k in self.__CommentsOrder:
            alignSpaceAmount = maxLen - len(k) + 4
            alignSpace = alignSpaceAmount * ' '
            comments += ('* '+ k + alignSpace + self.__fileComments[k] + '\n')

        comments += ('**/\n\n')

        return comments

    def generateCommentsInTheEnd(self):
        return ("/********************* (C) COPYRIGHT WEYNE CHEN *******END OF FILE ********/\n")

    def createSource(self):
        fh = open(self.__sourceName,mode = 'w',encoding='utf-8')
        cm = self.generateCommentsAtTop(self.__sourceName)
        cm += ("#include \"%s\"\n" %self.__headerName) 
        cm += ("\n"*5)
        cm += self.generateCommentsInTheEnd()
        fh.write(cm)
        fh.close()

    def createHeader(self):
        fh = open(self.__headerName,mode = 'w',encoding='utf-8')
        cm = self.generateCommentsAtTop(self.__headerName)
        cm += "#ifndef __%s_H\n" %self.__fileName.upper()
        cm += "#define __%s_H\n" %self.__fileName.upper()
        cm += ("\n"*5)
        cm += "#endif\n"
        cm += self.generateCommentsInTheEnd()
        fh.write(cm)
        fh.close()

    def createTemplatePairs(self):
        self.createSource()
        self.createHeader()


if __name__ == '__main__':
        if len(sys.argv) != 2:
            sys.stderr.write("please input corret parameter")
        else:
            s = sys.argv[1]
            ct = ctemplate(s)
            ct.createTemplatePairs()