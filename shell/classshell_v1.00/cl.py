#!usr/bin/env python3
#coding: utf-8
#cpnshell.py

import sys
import datetime
import os

class cl:

    __timeFormatFull = datetime.datetime.now().strftime('%Y/%m/%d %H:%M:%S')
    __timeFormatShort = datetime.datetime.now().strftime('%y%m%d')
    
    __encoding = 'gb2312' #'utf-8' 'gb2312' 'gbk'
    
    __clName = ''
    __clPath = ''
    __clOopcHeaderPath = 'oopc_v1.02\\oopc.h'
    __clStandTypeHeaderPath = 'standType\\standType.h'
    
    __fileComments = {'@copyright':':Copyright(C), 2018, pxf, person.',
        '@file':':',
        '@author':':pxf',
        '@version':':v1.0',
        '@date':':'+__timeFormatFull,
        '@brief':':',
        '@others':':',
        '@history':':'+__timeFormatShort+' pxf 初次建立'}
    __functionComments = {'@function':':',
        '@description':':',
        '@input':':',
        '@output':':',
        '@calls':':',
        '@calledBy':':',
        '@others':':'}

    __fCommentsOrder = ('@copyright','@file','@author','@version','@date','@brief','@others','@history')
    __funcCommentsOrder = ('@function','@description','@input','@output','@calls','@calledBy','@others')
    
    def __init__(self,clName,clPath):
        """根据输入参数初始化参数"""
        self.__clName = clName
        self.__clPath = clPath
        
    # ======================================================
    # 文件内具体代码生成函数
    # ======================================================
    # ------------------------------------------------------
    # 通用文件内注释
    def generateFileHeadComment(self,name):
        """根据输入名称生成头文件文件头注释"""
        # set filename for every file generate
        self.__fileComments['@file'] = ':'+name

        comments = ('/**************************************************************************\n')
        # find max length of string
        maxLen = 0
        for s in self.__fCommentsOrder:
            if(len(s) > maxLen):
                maxLen = len(s)
        # align space generate line
        for k in self.__fCommentsOrder:
            alignSpaceAmount = maxLen - len(k) + 4
            alignSpace = alignSpaceAmount * ' '
            comments += ('* '+ k + alignSpace + self.__fileComments[k] + '\n')
        comments += ('***************************************************************************/\n\n')
        return comments
    def generateFileEndComment(self):
        """根据生成文件结束注释"""
        return ("/**************************** Copyright(C) pxf ****************************/\n")
    # 根据输入名称生成函数注释
    def generateFunctionComment(self,name):
        """根据输入名称生成函数注释"""
        # set function name for every function generate
        self.__functionComments['@function'] = ':'+name

        comments = ('/***********************************************************\n')
        # find max length of string
        maxLen = 0
        for s in self.__funcCommentsOrder:
            if(len(s) > maxLen):
                maxLen = len(s)
        # align space generate line
        for k in self.__funcCommentsOrder:
            alignSpaceAmount = maxLen - len(k) + 4
            alignSpace = alignSpaceAmount * ' '
            comments += ('* '+ k + alignSpace + self.__functionComments[k] + '\n')
        comments += ('***********************************************************/\n')
        return comments
    
    # 类初始化函数注释
    def cpnHeaerAndSourceClassInitFuncComment(self,name,functype,brief):
        '''类初始化函数注释'''
        comments = ('/*'+brief+'\n')
        comments += ('* 输入: cthis %s类指针\n' %name)
        comments += ('* 输出: h%s cthis/OOPC_NULL\n' %name)
        comments += ('***********************************************/\n')
        comments += ('h%s %s_init%s\n' %(name,name,functype))
        comments += ('\n'*1)
        return comments
    # 类初功能函数注释
    def cpnHeaerAndSourceClassFuncComment(self,name,funcname,functype,brief):
        '''类初功能函数注释'''
        comments = ('/*'+brief+'\n')
        comments += ('* 输入: t %s类指针\n' %name)
        comments += ('* 输出: 无\n')
        comments += ('***********************************************/\n')
        comments += ('void %s_%s%s\n' %(name,funcname,functype))
        comments += ('\n'*1)
        return comments 
    
    # 构造函数注释
    def cpnHeaerAndSourceCCFuncComment(self,name,functype,brief):
        '''构造函数注释'''
        comments = ('/*'+brief+'\n')
        comments += ('* 输入: cthis %s类指针\n' %name)
        comments += ('* 输出: h%s cthis/OOPC_NULL\n' %name)
        comments += ('***********************************************/\n')
        comments += ('CC%s\n' %functype)
        #comments += ('\n'*1)
        return comments
    # 析构函数注释
    def cpnHeaerAndSourceCDFuncComment(self,name,functype,brief):
        '''析构函数注释'''
        comments = ('/*'+brief+'\n')
        comments += ('* 输入: cthis %s类指针\n' %name)
        comments += ('* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE\n')
        comments += ('***********************************************/\n')
        comments += ('CD%s\n' %functype)
        comments += ('\n'*1)
        return comments
    # ------------------------------------------------------
    # ======================================================    
        
        
    # ======================================================
    # 具体文件生成函数
    # ======================================================
    # 生成头文件
    def createHeader(self,name):
        '''生成头文件'''
        fh = open(name+'.h',mode = 'w',encoding=self.__encoding)
        cm = self.generateFileHeadComment(name+'.h')
        cm += "#ifndef %s_H_\n" %name.upper()
        cm += "#define %s_H_\n" %name.upper()
        cm += ("\n"*1)
        if self.__clPath != '':
            refPath = '..\\'*len(self.__clPath.split('\\'))
        else:
            refPath = ''
        cm += ('#include \"'+refPath+self.__clStandTypeHeaderPath+'\"\n') 
        cm += ('#include \"'+refPath+self.__clOopcHeaderPath+'\"\n') 
        cm += ('\n'*1)
        cm += ('/***********************************************************\n')
        cm += ('* 接口定义\n')
        cm += ('***********************************************************/\n')
        cm += ('/*接口声明\n')
        cm += ('***********************************************/\n')
        cm += ('//INF(get){\n//  uint16(*get)(void);\n//};\n')
        cm += ('//TODO\n')
        cm += ('\n'*2)
        cm += ('/***********************************************************\n')
        cm += ('* %s类定义\n' %name)
        cm += ('***********************************************************/\n')
        cm += ('/*%s类声明\n' %name)
        cm += ('***********************************************/\n')
        cm += ('CL(%s){\n' %name)
        cm += ('    h%s self;\n    h%s (*init)(h%s cthis);\n' %(name,name,name))
        cm += ('\n'*1)
        cm += ('    // %s类参数\n' %name)
        cm += ('    //TODO\n')
        cm += ('\n'*1)
        cm += ('    // %s类功能函数\n    void (*func)(h%s t);\n' %(name,name))
        cm += ('    //TODO\n')
        cm += ('};\n')
        cm += ("\n"*2)
        cm += "#endif /* %s_H_ */\n\n" %name.upper()
        cm += self.generateFileEndComment()
        fh.write(cm)
        fh.close()    
    # 生成源文件
    def createSource(self,name):
        '''生成源文件'''
        fh = open(name+'.c',mode = 'w',encoding=self.__encoding)
        cm = self.generateFileHeadComment(name+'.c')
        cm += ("#include \"%s.h\"\n" %name) 
        cm += ("\n"*1)
        #cm += self.generateFunctionComment(name+'()')
        #cm += ("void %s(void)\n{}\n" %name)
        cm += ('/***********************************************************\n')
        cm += ('* %s类定义\n' %name)
        cm += ('***********************************************************/\n')
        funcEntity = ('(h%s cthis){\n' %name)
        funcEntity += ('    // 功能函数配置\n')
        funcEntity += ('    //cthis->func = func;\n')
        funcEntity += ('    //TODO\n')
        funcEntity += ('\n    // 参数配置\n')
        funcEntity += ('    //TODO\n')
        funcEntity += ('\n    return cthis;\n}')
        cm += self.cpnHeaerAndSourceClassInitFuncComment(name,funcEntity,'%s类初始化函数' %name)
        funcEntity = ('(h%s t){\n' %name)
        funcEntity += ('    //TODO\n')
        funcEntity += ('}')
        cm += self.cpnHeaerAndSourceClassFuncComment(name,'func',funcEntity,'%s类功能函数' %name)
        funcEntity = ('(%s){\n' %name)
        funcEntity += ('    // 功能函数配置\n')
        funcEntity += ('    cthis->init = %s_init;\n' %name)
        funcEntity += ('    cthis->func = %s_func;\n' %name)
        funcEntity += ('    //TODO\n')
        funcEntity += ('\n    // 参数配置\n')
        funcEntity += ('    //TODO\n')
        funcEntity += ('\n    return cthis;\n}')
        cm += self.cpnHeaerAndSourceCCFuncComment('vfbO'+name,funcEntity,'%s类构造函数' %name)
        funcEntity = ('(%s){\n    return OOPC_TRUE;\n}' %name)
        cm += self.cpnHeaerAndSourceCDFuncComment(name,funcEntity,'%s类析构函数' %name)
        cm += ('\n'*1)
        cm += self.generateFileEndComment()
        fh.write(cm)
        fh.close()
    # ======================================================        
        
        
        
    # ======================================================
    # 模板生成
    # ======================================================    
    def createTemp(self):    
        '''模板生成功能函数'''
        if self.__clPath != '':
            if not os.path.exists(self.__clPath):
                os.makedirs(self.__clPath)
            os.chdir(self.__clPath)
        self.createHeader(self.__clName)
        self.createSource(self.__clName)
    # ======================================================    

    
if __name__ == '__main__':
    if len(sys.argv) != 2 and len(sys.argv) != 3:
        sys.stderr.write("please input corret parameter\n")
    else:
        if len(sys.argv) == 3:
            clPath = sys.argv[2]
        else:
            clPath = ''
        clName = sys.argv[1]
        clTemp = cl(clName,clPath)
        clTemp.createTemp()        

        
        
        
        
        