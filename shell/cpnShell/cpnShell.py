#!usr/bin/env python3
#coding: utf-8
#ctemp.py

import sys
import datetime
import os

class cpnShell:

    __timeFormatFull = datetime.datetime.now().strftime('%Y/%m/%d %H:%M:%S')
    __timeFormatShort = datetime.datetime.now().strftime('%y%m%d')
    
    __cpnType = ' '
    __cpnName = ' '
    __cpnTypeCorrect = 0
    __cpnFolderExist = 0
    
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
    
    __cpnFolder = {'01_std':' ',
        '02_bm':' ',
        '03_bsp':' ',
        '04_abi':' ',
        '05_cpnInit':' ',
        '06_cas':' ',
        '07_cs':' ',
        '08_cuf':' ',
        '09_cpc':' ',
        '10_ccc':' ',
        '11_vfbM':' ',
    }

    def __init__(self,cpnType,cpnName):
        """根据输入参数初始化参数
        
        主要功能：1.生成文件名称"""
        self.__cpnType = cpnType
        self.__cpnName = cpnName
        if(self.__cpnType == 'cas'):
            __cpnTypeCorrect = 1
            self.__cpnFolder['03_bsp'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['04_abi'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['06_cas'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['11_vfbM'] = self.__cpnType+self.__cpnName
            
            self.__cpnConstructorCommand['03_bsp'] = self.bspcpnGenFunc
            self.__cpnConstructorCommand['04_abi'] = self.abicpnGenFunc
            self.__cpnConstructorCommand['06_cas'] = self.cascpnGenFunc
            self.__cpnConstructorCommand['11_vfbM'] = self.vfbMcpnGenFunc
        elif(self.__cpnType == 'cs'):
            __cpnTypeCorrect = 1
            self.__cpnFolder['04_abi'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['06_cs'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['11_vfbM'] = self.__cpnType+self.__cpnName
            
            self.__cpnConstructorCommand['04_abi'] = self.abicpnGenFunc
            self.__cpnConstructorCommand['06_cs'] = self.cscpnGenFunc
            self.__cpnConstructorCommand['11_vfbM'] = self.vfbMcpnGenFunc
        elif(self.__cpnType == 'cuf'):
            __cpnTypeCorrect = 1
            self.__cpnFolder['04_abi'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['08_cuf'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['11_vfbM'] = self.__cpnType+self.__cpnName
            
            self.__cpnConstructorCommand['04_abi'] = self.abicpnGenFunc
            self.__cpnConstructorCommand['08_cuf'] = self.cufcpnGenFunc
            self.__cpnConstructorCommand['11_vfbM'] = self.vfbMcpnGenFunc
        elif(self.__cpnType == 'cpc'):
            __cpnTypeCorrect = 1
            self.__cpnFolder['09_cpc'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['11_vfbM'] = self.__cpnType+self.__cpnName
            
            self.__cpnConstructorCommand['09_cpc'] = self.cpccpnGenFunc
            self.__cpnConstructorCommand['11_vfbM'] = self.vfbMcpnGenFunc            
        elif(self.__cpnType == 'ccc'):
            __cpnTypeCorrect = 1
            self.__cpnFolder['10_ccc'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['11_vfbM'] = self.__cpnType+self.__cpnName
            
            self.__cpnConstructorCommand['10_ccc'] = self.ccccpnGenFunc
            self.__cpnConstructorCommand['11_vfbM'] = self.vfbMcpnGenFunc    
        else:
            __cpnTypeCorrect = 0
            sys.stderr.write("cpnType parameter err, please input corret parameter")

    # ======================================================
    # 文件内具体代码生成函数
    # ======================================================
    def generateFileHeadComment(self,name):
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
        return ("/**************************** Copyright(C) pxf ****************************/\n")
        
    def generateFunctionComment(self,name):
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

    def createSource(self,name):
        fh = open(name+'.c',mode = 'w',encoding='utf-8')
        cm = self.generateFileHeadComment(name+'.c')
        cm += ("#include \"%s.h\"\n" %name) 
        cm += ("\n"*2)
        cm += self.generateFunctionComment(name+'()')
        cm += ("void %s(void)\n{}\n" %name)
        cm += ("\n"*2)
        cm += self.generateFileEndComment()
        fh.write(cm)
        fh.close()

    def createHeader(self,name):
        fh = open(name+'.h',mode = 'w',encoding='utf-8')
        cm = self.generateFileHeadComment(name+'.h')
        cm += "#ifndef %s_H_\n" %name.upper()
        cm += "#define %s_H_\n" %name.upper()
        cm += ("\n"*2)
        cm += self.generateFunctionComment(name+'()')
        cm += ("void %s(void);\n" %name)
        cm += ("\n"*2)
        cm += "#endif\n\n"
        cm += self.generateFileEndComment()
        fh.write(cm)
        fh.close()
    # ======================================================
    
    #def createTemplatePairs(self):
    #    self.createSource()
    #    self.createHeader()

        
        
    # ======================================================
    # 文件生成控制函数
    # ======================================================
    def cpnGenDefaultFunc(self):
        sys.stderr.write("component generate use default function")
        
    __cpnConstructorCommand = {'01_std':cpnGenDefaultFunc,
        '02_bm':cpnGenDefaultFunc,
        '03_bsp':cpnGenDefaultFunc,
        '04_abi':cpnGenDefaultFunc,
        '05_cpnInit':cpnGenDefaultFunc,
        '06_cas':cpnGenDefaultFunc,
        '07_cs':cpnGenDefaultFunc,
        '08_cuf':cpnGenDefaultFunc,
        '09_cpc':cpnGenDefaultFunc,
        '10_ccc':cpnGenDefaultFunc,
        '11_vfbM':cpnGenDefaultFunc,
    }
    
    def cpnFolderExistJudgeAndCreat(self):
        """对组件所有需要的文件进行判断是否存在
        
        1.如果文件夹存在由不会生成相应的组件，存在文件夹则可能存在文件，不应该对存在的文件进行覆盖
        2.如果所有文件夹都不存在，则会生成所有需要的文件夹
        3.所有操作都是切到对应文件夹进行操作之后，再退回到脚本所有文件夹"""
        for cpnpath in self.__cpnFolder:
            if((self.__cpnFolder[cpnpath] != ' ')and(self.__cpnFolderExist == 0)):
                if(os.path.exists(cpnpath)):
                    os.chdir(cpnpath)
                    if(os.path.exists(self.__cpnFolder[cpnpath])):
                        self.__cpnFolderExist = 1
                        sys.stderr.write("%s reference folder exist, please delete and try again")
                    else:
                        os.mkdir(self.__cpnFolder[cpnpath])
                    os.chdir('..')
                else:
                    os.makedirs(cpnpath+'\\'+self.__cpnFolder[cpnpath])

    def bspcpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder['03_bsp'] != ' '):
            os.chdir('03_bsp\\'+self.__cpnFolder['03_bsp'])
            self.createSource('bsp'+self.__cpnType+self.__cpnName)
            self.createHeader('bsp'+self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')
            
    def abicpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder['04_abi'] != ' '):
            os.chdir('04_abi\\'+self.__cpnFolder['04_abi'])
            self.createSource('abi'+self.__cpnType+self.__cpnName)
            self.createHeader('abi'+self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')    
        
    def cascpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder['06_cas'] != ' '):
            os.chdir('06_cas\\'+self.__cpnFolder['06_cas'])
            self.createSource(self.__cpnType+self.__cpnName)
            self.createHeader(self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')
        
    def cscpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder['07_cs'] != ' '):
            os.chdir('07_cs\\'+self.__cpnFolder['07_cs'])
            self.createSource(self.__cpnType+self.__cpnName)
            self.createHeader(self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')
    
    def cufcpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder['08_cuf'] != ' '):
            os.chdir('08_cuf\\'+self.__cpnFolder['08_cuf'])
            self.createSource(self.__cpnType+self.__cpnName)
            self.createHeader(self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')

    def cpccpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder['09_cpc'] != ' '):
            os.chdir('09_cpc\\'+self.__cpnFolder['09_cpc'])
            self.createSource(self.__cpnType+self.__cpnName)
            self.createHeader(self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')

    def ccccpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder['10_ccc'] != ' '):
            os.chdir('10_ccc\\'+self.__cpnFolder['10_ccc'])
            self.createSource(self.__cpnType+self.__cpnName)
            self.createHeader(self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')

    def vfbMcpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder['11_vfbM'] != ' '):
            os.chdir('11_vfbM\\'+self.__cpnFolder['11_vfbM'])
            self.createSource('vfbM'+self.__cpnType+self.__cpnName)
            self.createHeader('vfbM'+self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')
            

    
    # ======================================================
        
        
    def createTemp(self):    
        self.cpnFolderExistJudgeAndCreat()
        for folder in self.__cpnFolder:
            if(self.__cpnFolder[folder] != ' '):
                self.__cpnConstructorCommand[folder]()
        
        
if __name__ == '__main__':
    if len(sys.argv) != 3:
        sys.stderr.write("please input corret parameter")
    else:
        cpnType = sys.argv[1]
        cpnName = sys.argv[2]
        cpn = cpnShell(cpnType,cpnName)
        cpn.createTemp()