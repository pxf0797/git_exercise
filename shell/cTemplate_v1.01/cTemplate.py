#!usr/bin/env python3
#coding: utf-8
#cTemplate.py

import sys
import datetime

class cTemplate:
    """文件生成脚本
    使用方法：python sm.py filename
    脚本只能有3个参数，filename根据需要选取"""
    __encoding = 'gb2312' #'utf-8' 'gb2312' ''
    __fileName = ' '
    __sourceName = ' '
    __headerName = ' '
    __timeFormatFull = datetime.datetime.now().strftime('%Y/%m/%d %H:%M:%S')
    __timeFormatShort = datetime.datetime.now().strftime('%y%m%d')
    __fileComments = {'@copyright':':Copyright(C), 2019, pxf, person.',
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
    __functionComments2 = {'名称':':无',
                      '输入':':无',
                      '输出':':无',
                      '其他':':无',
    }

    __fCommentsOrder = ('@copyright','@file','@author','@version','@date','@brief','@others','@history')
    __funcCommentsOrder = ('@function','@description','@input','@output','@calls','@calledBy','@others')
    __funcCommentsOrder2 = ('名称','输入','输出','其他')

    def __init__(self,s):
        """根据输入参数初始化参数
        
        主要功能：1.生成文件名称"""
        self.__fileName = s
        self.__sourceName = s + ".c"
        self.__headerName = s + '.h'

        
    #========================================================
    # 文件基础生成函数
    #--------------------------------------------------------
    def generateFileHeadComment(self,name):
        """生成文件头注释"""
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
        """生成文件尾注释"""
        return ("/**************************** Copyright(C) pxf ****************************/\n")
        
    def generateFunctionComment(self,name):
        """生成函数头注释"""
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
        
    def generateFunctionComment2(self,name,input,output,others):
        """生成函数头注释类型2"""
        #set function name for every function generate
        self.__functionComments2['名称'] = ':'+name
        self.__functionComments2['输入'] = ':'+input
        self.__functionComments2['输出'] = ':'+output
        self.__functionComments2['其他'] = ':'+others
        comments = ('')
        #find max length of string
        maxLen = 0
        for s in self.__funcCommentsOrder2:
            if(len(s) > maxLen):
                maxLen = len(s)
        #align space generate line
        for k in self.__funcCommentsOrder2:
            alignSpaceAmount = maxLen - len(k) + 1
            alignSpace = alignSpaceAmount * ' '
            if(k == '名称'):
                comments += ('/*'+ k + alignSpace + self.__functionComments2[k] + '\n')
            else:
                comments += ('* '+ k + alignSpace + self.__functionComments2[k] + '\n')
        comments += ('***********************************************/\n')
        return comments
    #========================================================

    
    #========================================================
    # 模板生成源文件及头文件控制函数
    #--------------------------------------------------------
    def createSource(self):
        """生成源文件"""
        fh = open(self.__sourceName,mode = 'w',encoding=self.__encoding)
        cm = self.generateFileHeadComment(self.__sourceName)
        cm += ("#include \"%s\"\n" %self.__headerName) 
        cm += ("\n"*2)
        cm += self.generateFunctionComment2(self.__fileName+'()','无','无','无')
        cm += ("void %s(void)\n{}\n" %self.__fileName)
        cm += ("\n"*2)
        cm += self.generateFileEndComment()
        fh.write(cm)
        fh.close()

    def createHeader(self):
        """生成头文件"""
        fh = open(self.__headerName,mode = 'w',encoding=self.__encoding)
        cm = self.generateFileHeadComment(self.__headerName)
        cm += "#ifndef %s_H_\n" %self.__fileName.upper()
        cm += "#define %s_H_\n" %self.__fileName.upper()
        cm += ("\n"*2)
        cm += self.generateFunctionComment2(self.__fileName+'()','无','无','无')
        cm += ("void %s(void);\n" %self.__fileName)
        cm += ("\n"*2)
        cm += "#endif /*%s_H_*/\n\n" %self.__fileName.upper()
        cm += self.generateFileEndComment()
        fh.write(cm)
        fh.close()

    def createTemplate(self):
        """模板生成"""
        self.createSource()
        self.createHeader()
    #========================================================

if __name__ == '__main__':
    if len(sys.argv) != 2:
        sys.stderr.write("please input corret parameter !!!")
    else:
        s = sys.argv[1]
        ct = cTemplate(s)
        ct.createTemplate()