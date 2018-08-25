#!usr/bin/env python3
#coding: utf-8
#ctemp.py

import sys
import datetime


class ctemplate:

    __fileName = ' '
    __sourceName = ' '
    __headerName = ' '
    __timeFormatFull = datetime.datetime.now().strftime('%Y/%m/%d %H:%M:%S')
    __timeFormatShort = datetime.datetime.now().strftime('%y%m%d')
    __fileComments = {'@copyright':':Copyright(C), 2018, pxf, person.',
                      '@file':':',
                      '@author':':pxf',
                      '@version':':v1.0',
                      '@date':':'+__timeFormatFull,
                      '@brief':':',
                      '@others':':',
                      '@history':':'+__timeFormatShort+' pxf 初建立',
    }
    __functionComments = {'@function':':',
                      '@description':':',
                      '@input':':',
                      '@output':':',
                      '@calls':':',
                      '@calledBy':':',
                      '@others':':',
    }

    __fCommentsOrder = ('@copyright','@file','@author','@version','@date','@brief','@others','@history')
    __funcCommentsOrder = ('@function','@description','@input','@output','@calls','@calledBy','@others')

    def __init__(self,s):
        """根据输入参数初始化参数
        
        主要功能：1.生成文件名称"""
        self.__fileName = s
        self.__sourceName = s + ".c"
        self.__headerName = s + '.h'

    def generateFileHeadComment(self,name):
        #set filename for every file generate
        self.__fileComments['@file'] = ':'+name

        comments = ('/**************************************************************************\n')

        #find max length of string
        maxLen = 0
        for s in self.__fCommentsOrder:
            if(len(s) > maxLen):
                maxLen = len(s)
                
        #align space generate line
        for k in self.__fCommentsOrder:
            alignSpaceAmount = maxLen - len(k) + 4
            alignSpace = alignSpaceAmount * ' '
            comments += ('* '+ k + alignSpace + self.__fileComments[k] + '\n')

        comments += ('***************************************************************************/\n\n')

        return comments

    def generateFileEndComment(self):
        return ("/**************************** Copyright(C) pxf ****************************/\n")
        
    def generateFunctionComment(self,name):
        #set function name for every function generate
        self.__functionComments['@function'] = ':'+name

        comments = ('/***********************************************************\n')

        #find max length of string
        maxLen = 0
        for s in self.__funcCommentsOrder:
            if(len(s) > maxLen):
                maxLen = len(s)
                
        #align space generate line
        for k in self.__funcCommentsOrder:
            alignSpaceAmount = maxLen - len(k) + 4
            alignSpace = alignSpaceAmount * ' '
            comments += ('* '+ k + alignSpace + self.__functionComments[k] + '\n')

        comments += ('***********************************************************/\n')

        return comments

    def createSource(self):
        fh = open(self.__sourceName,mode = 'w',encoding='utf-8')
        cm = self.generateFileHeadComment(self.__sourceName)
        cm += ("#include \"%s\"\n" %self.__headerName) 
        cm += ("\n"*2)
        cm += self.generateFunctionComment(self.__fileName+'()')
        cm += ("void %s(void)\n{}\n" %self.__fileName)
        cm += ("\n"*2)
        cm += self.generateFileEndComment()
        fh.write(cm)
        fh.close()

    def createHeader(self):
        fh = open(self.__headerName,mode = 'w',encoding='utf-8')
        cm = self.generateFileHeadComment(self.__headerName)
        cm += "#ifndef %s_H_\n" %self.__fileName.upper()
        cm += "#define %s_H_\n" %self.__fileName.upper()
        cm += ("\n"*2)
        cm += self.generateFunctionComment(self.__fileName+'()')
        cm += ("void %s(void);\n" %self.__fileName)
        cm += ("\n"*2)
        cm += "#endif\n\n"
        cm += self.generateFileEndComment()
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