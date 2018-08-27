#!usr/bin/env python3
#coding: utf-8
#cpnshell.py

import sys
import datetime
import os

class cpnShell:

    __timeFormatFull = datetime.datetime.now().strftime('%Y/%m/%d %H:%M:%S')
    __timeFormatShort = datetime.datetime.now().strftime('%y%m%d')
    
    __encoding = 'utf-8' #'utf-8' 'gb2312' ''
    
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
        '@history':':'+__timeFormatShort+' pxf 初次建立',
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
    
    __cpnTypeIndex = {'std':'01',
        'bm':'02',
        'bsp':'03',
        'abi':'04',
        'cpnInit':'05',
        'cas':'06',
        'cs':'07',
        'cuf':'08',
        'cpc':'09',
        'ccc':'10',
        'vfbM':'11',
    }
    __cpnFolder = {'std':' ',
        'bm':' ',
        'bsp':' ',
        'abi':' ',
        'cpnInit':' ',
        'cas':' ',
        'cs':' ',
        'cuf':' ',
        'cpc':' ',
        'ccc':' ',
        'vfbM':' ',
    }
    __cpnConstructorCommand = {'std':' ',
        'bm':' ',
        'bsp':' ',
        'abi':' ',
        'cpnInit':' ',
        'cas':' ',
        'cs':' ',
        'cuf':' ',
        'cpc':' ',
        'ccc':' ',
        'vfbM':' ',
    }

    def __init__(self,cpnType,cpnName):
        """根据输入参数初始化参数
        
        主要功能：1.生成文件名称"""
        self.__cpnType = cpnType
        self.__cpnName = cpnName
        if(self.__cpnType == 'cas'):
            __cpnTypeCorrect = 1
            self.__cpnFolder['bsp'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['abi'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['cas'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['vfbM'] = self.__cpnType+self.__cpnName
            
            self.cpnConstructorCommandInit()
            self.__cpnConstructorCommand['bsp'] = self.bspcpnGenFunc
            self.__cpnConstructorCommand['abi'] = self.abicpnGenFunc
            self.__cpnConstructorCommand['cas'] = self.cpnGenFunc #self.cascpnGenFunc
            self.__cpnConstructorCommand['vfbM'] = self.vfbMcpnGenFunc
        elif(self.__cpnType == 'cs'):
            __cpnTypeCorrect = 1
            self.__cpnFolder['abi'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['cs'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['vfbM'] = self.__cpnType+self.__cpnName
            
            self.cpnConstructorCommandInit()
            self.__cpnConstructorCommand['abi'] = self.abicpnGenFunc
            self.__cpnConstructorCommand['cs'] = self.cpnGenFunc #self.cscpnGenFunc
            self.__cpnConstructorCommand['vfbM'] = self.vfbMcpnGenFunc
        elif(self.__cpnType == 'cuf'):
            __cpnTypeCorrect = 1
            self.__cpnFolder['abi'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['cuf'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['vfbM'] = self.__cpnType+self.__cpnName
            
            self.cpnConstructorCommandInit()
            self.__cpnConstructorCommand['abi'] = self.abicpnGenFunc
            self.__cpnConstructorCommand['cuf'] = self.cpnGenFunc #self.cufcpnGenFunc
            self.__cpnConstructorCommand['vfbM'] = self.vfbMcpnGenFunc
        elif(self.__cpnType == 'cpc'):
            __cpnTypeCorrect = 1
            self.__cpnFolder['cpc'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['vfbM'] = self.__cpnType+self.__cpnName
            
            self.cpnConstructorCommandInit()
            self.__cpnConstructorCommand['cpc'] = self.cpnGenFunc #self.cpccpnGenFunc
            self.__cpnConstructorCommand['vfbM'] = self.vfbMcpnGenFunc            
        elif(self.__cpnType == 'ccc'):
            __cpnTypeCorrect = 1
            self.__cpnFolder['ccc'] = self.__cpnType+self.__cpnName
            self.__cpnFolder['vfbM'] = self.__cpnType+self.__cpnName
            
            self.cpnConstructorCommandInit()
            self.__cpnConstructorCommand['ccc'] = self.cpnGenFunc #self.ccccpnGenFunc
            self.__cpnConstructorCommand['vfbM'] = self.vfbMcpnGenFunc    
        else:
            __cpnTypeCorrect = 0
            sys.stderr.write("cpnType parameter err, please input corret parameter\n")

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
        
    def cpnHeaerAndSourceClassInitFuncComment(self,name,functype,brief):
        '''类初始化函数注释'''
        comments = ('/*'+brief+'\n')
        comments += ('* 输入: cthis %s类指针\n' %name)
        comments += ('* 输出: h%s cthis/OOPC_NULL\n' %name)
        comments += ('***********************************************/\n')
        comments += ('h%s %s_init%s\n' %(name,name,functype))
        comments += ('\n'*1)
        return comments
    def cpnHeaerAndSourceClassFuncComment(self,name,funcname,functype,brief):
        '''类初始化函数注释'''
        comments = ('/*'+brief+'\n')
        comments += ('* 输入: t %s类指针\n' %name)
        comments += ('* 输出: 无\n')
        comments += ('***********************************************/\n')
        comments += ('h%s %s_%s%s\n' %(name,name,funcname,functype))
        comments += ('\n'*1)
        return comments    
    def cpnHeaerAndSourceCCFuncComment(self,name,functype,brief):
        '''构造函数注释'''
        comments = ('/*'+brief+'\n')
        comments += ('* 输入: cthis %s类指针\n' %name)
        comments += ('* 输出: h%s cthis/OOPC_NULL\n' %name)
        comments += ('***********************************************/\n')
        comments += ('CC%s\n' %functype)
        #comments += ('\n'*1)
        return comments
    def cpnHeaerAndSourceCDFuncComment(self,name,functype,brief):
        '''析构函数注释'''
        comments = ('/*'+brief+'\n')
        comments += ('* 输入: cthis %s类指针\n' %name)
        comments += ('* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE\n')
        comments += ('***********************************************/\n')
        comments += ('CD%s\n' %functype)
        comments += ('\n'*1)
        return comments
    def cpnHeaerAndSourceSMFuncComment(self,name,sta,functype,brief):
        '''状态机状态处理函数注释'''
        comments = ('/*'+brief+'\n')
        comments += ('* 输入: hStaRec 状态记录结构体指针\n')
        comments += ('* 输出: 无\n')
        comments += ('***********************************************/\n')
        comments += ('void sm%s_act_%s%s\n' %(name,sta,functype))
        comments += ('\n'*1)
        return comments
    def cpnHeaerAndSourceInitFuncComment(self,ext,name,functype,brief):
        '''组件初始化相关函数注释'''
        comments = ('/*'+brief+'\n')
        comments += ('* 输入: 无\n')
        comments += ('* 输出: int16 0-成功,-1-失败\n')
        comments += ('***********************************************/\n')
        comments += (ext+'int16 %sInit%s\n' %(name,functype))
        comments += ('\n'*1)
        return comments
    def cpnHeaerAndSourceSchFuncComment(self,ext,name,functype,brief):
        '''任务调度函数注释'''
        comments = ('/*'+brief+'\n')
        comments += ('* 输入: 无\n')
        comments += ('* 输出: 无\n')
        comments += ('***********************************************/\n')
        comments += (ext+'void %sSch%s\n' %(name,functype))
        comments += ('\n'*1)
        return comments
    def cpnHeaerInitFuncComment(self,name,ext,brief):
        '''组件初始化相关函数注释'''
        comments = ('/*'+brief+'\n')
        comments += ('* 输入: 无\n')
        comments += ('* 输出: int16 0-成功,-1-失败\n')
        comments += ('***********************************************/\n')
        comments += (ext+'int16 %sInit(void);\n' %name)
        comments += ('\n'*1)
        return comments
    def cpnHeaerSchFuncComment(self,name,ext,brief):
        '''任务调度函数注释'''
        comments = ('/*'+brief+'\n')
        comments += ('* 输入: 无\n')
        comments += ('* 输出: 无\n')
        comments += ('***********************************************/\n')
        comments += (ext+'void %sSch(void);\n' %name)
        comments += ('\n'*1)
        return comments    
    def cpnHeaderGenerateCpnInitAndSchComment(self,name):
        '''组件初始化及调度注释'''
        comments = ('/***********************************************************\n')
        comments += ('* 组件初始化\n')
        comments += ('***********************************************************/\n')
        comments += self.cpnHeaerAndSourceInitFuncComment('','vfbI'+name,'(void);','组件输入初始化')
        comments += self.cpnHeaerAndSourceInitFuncComment('',name,'(void);','组件初始化')
        comments += self.cpnHeaerAndSourceInitFuncComment('','vfbO'+name,'(void);','组件输出初始化')
        comments += self.cpnHeaerAndSourceInitFuncComment('extern ','vfbM'+name,'(void);','管理组件初始化外部声明')
        comments += ('\n'*1)
        comments += ('/***********************************************************\n')
        comments += ('* 组件调度\n')
        comments += ('***********************************************************/\n')
        comments += self.cpnHeaerAndSourceSchFuncComment('',name,'(void);','组件进行调度')
        comments += ('\n'*1)
        return comments
        
    def cpnHeaderGenerateVfbOcpnComment(self,name):
        '''组件输出类注释'''
        comments = ('/***********************************************************\n')
        comments += ('* 组件输出类定义\n')
        comments += ('***********************************************************/\n')
        comments += ('/*组件输出类声明\n')
        comments += ('***********************************************/\n')
        comments += ('CL(vfbO%s){\n' %name)
        comments += ('    hvfbO%s self;\n    hvfbO%s (*init)(hvfbO%s cthis);\n' %(name,name,name))
        comments += ('\n'*1)
        comments += ('    // 组件调度参数\n    schParam schParam;\n')
        comments += ('\n'*1)
        comments += ('    // 示例组件输出类功能函数\n    //void (*example)(hvfbO%s t);\n' %name)
        comments += ('    //TODO\n')
        comments += ('};\n')
        comments += ('\n'*1)
        comments += ('/*组件输出类外部接口声明\n* 命名方式: 存放类+实际类+实际类功能\n')
        comments += ('***********************************************/\n')
        comments += ('//extern void vfbM%s_vfbO%s_example(hvfbO%s t);\n//TODO\n' %(name,name,name))
        comments += ('\n'*1)
        comments += ('/*组件输出类实例\n')
        comments += ('***********************************************/\n')
        comments += ('extern vfbO%s vfbO%sA;\n' %(name,name))
        comments += ('\n'*1)
        return comments
        
    def cpnHeaderGenerateCpnComment(self,name):
        '''组件类注释'''
        comments = ('/***********************************************************\n')
        comments += ('* 组件类定义\n')
        comments += ('***********************************************************/\n')
        comments += ('/*组件状态机状态\n')
        comments += ('* 有两个状态init/default，状态list不显示，默认给出\n')
        comments += ('* 状态list需根据实际应用进行重写，list修改后相应状态函数得对应修改\n')
        comments += ('***********************************************/\n')
        comments += ('#define SM_%s_STA_LIST(_) \\\n' %name.upper())
        comments += ('    _(sm%s, sta1)\\\n    _(sm%s, sta2)\n' %(name,name))
        comments += ('\n'*1)
        comments += ('/*组件状态机定义\n')
        comments += ('***********************************************/\n')
        comments += ('SMDC(sm%s, SM_%s_STA_LIST)\n{\n' %(name,name.upper()))
        comments += ('    sta next;\n    //TODO\n')
        comments += ('\n'*1)
        comments += ('    // 注入组件类\n    void *%s;\n};\n' %name)
        comments += ('\n'*2)
        comments += ('/*组件类声明\n')
        comments += ('***********************************************/\n')
        comments += ('CL(%s){\n' %name)
        comments += ('    h%s self;\n    h%s (*init)(h%s cthis, hstaAct sm%s, hvfbO%s vfbO%s);\n' %(name,name,name,name,name,name))
        comments += ('\n'*1)
        comments += ('    // 组件运行状态机\n    sm%sRec sm%sRec;\n    hstaAct sm%s;\n' %(name,name,name))
        comments += ('\n'*1)
        comments += ('    // 组件运行功能函数\n    void (*run)(h%s t);\n' %name)
        comments += ('    //void (*example)(h%s t);\n    //TODO\n' %name)
        comments += ('\n'*1)
        comments += ('    // 注入组件输出类\n    INJ(vfbO%s, vfbO%s);\n};\n' %(name,name))
        comments += ('\n'*1)
        comments += ('/*异步调度功能函数\n* 命名方式: 存放类+实际类+实际类功能\n')
        comments += ('***********************************************/\n')
        comments += ('//void %s_abi_example(void);\n//TODO\n' %name)
        comments += ('\n'*1)
        comments += ('/*组件类实例\n')
        comments += ('***********************************************/\n')
        comments += ('extern %s %sA;\n' %(name,name))
        comments += ('\n'*1)
        return comments
        
    def cpnHeaderGenerateVfbIcpnComment(self,name):
        '''组件输入类注释'''
        comments = ('/***********************************************************\n')
        comments += ('* 组件输入类定义\n')
        comments += ('***********************************************************/\n')
        comments += ('/*组件输入类声明\n')
        comments += ('***********************************************/\n')
        comments += ('CL(vfbI%s){\n' %name)
        comments += ('    hvfbI%s self;\n    hvfbI%s (*init)(hvfbI%s cthis, h%s %s);\n' %(name,name,name,name,name))
        comments += ('\n'*1)
        comments += ('    //void (*example)(hvfbI%s t);\n    //TODO\n' %name)
        comments += ('\n'*1)
        comments += ('    // 注入组件类\n    INJ(%s, %s);\n};\n' %(name,name))
        comments += ('\n'*1)
        comments += ('/*组件输入类实例\n')
        comments += ('***********************************************/\n')
        comments += ('extern vfbI%s vfbI%sA;\n' %(name,name))
        comments += ('\n'*1)
        return comments
    
    def cpnHeaderGenerateVfbMcpnComment(self,name):
        '''组件管理类注释'''
        comments = ('/***********************************************************\n')
        comments += ('* 组件管理类定义\n')
        comments += ('***********************************************************/\n')
        comments += ('/*组件管理类声明\n')
        comments += ('***********************************************/\n')
        comments += ('CL(vfbM%s){\n' %name)
        comments += ('    hvfbM%s self;\n    hvfbM%s (*init)(hvfbM%s cthis, hvfbO%s vfbO%s, hvfbIcasSch vfbIcasSch);\n' %(name,name,name,name,name))
        comments += ('\n'*1)
        comments += ('    //void (*example)(hvfbM%s t);\n    //TODO\n' %name)
        comments += ('\n'*1)
        comments += ('    // 注入组件类\n    INJ(vfbO%s, vfbO%s);\n' %(name,name))
        comments += ('    INJ(vfbIcasSch, vfbIcasSch);\n}\n')
        comments += ('\n'*1)
        comments += ('/*组件输出类接口声明\n* 命名方式: 存放类+实际类+实际类功能\n')
        comments += ('***********************************************/\n')
        comments += ('//void vfbM%s_vfbO%s_example(hvfbO%s t);\n' %(name,name,name))
        comments += ('\n'*1)
        comments += ('/*组件管理类实例\n')
        comments += ('***********************************************/\n')
        comments += ('extern vfbM%s vfbM%sA;\n' %(name,name))
        comments += ('\n'*1)
        return comments
    
    def cpnSourceInitFuncEntity(self,initName,outName,injSource):
        funcEntity = ("(void){\n")
        funcEntity += ("    int16 rtv = 0;\n\n")
        funcEntity += ("    CN(%s, &%sA, %s);\n" %(initName,initName,injSource))
        funcEntity += ("    if(OPRS(%sA) != OOPC_NULL){\n" %initName)
        funcEntity += ("        rtv = %sInit();\n    }else{\n        rtv = -1;\n    }\n" %outName)
        funcEntity += ("\n    return rtv;\n}")
        return funcEntity
    def cpnSourceGenerateVfbIcpnComment(self,name):
        '''组件输入定义'''
        comments = ('/***********************************************************\n')
        comments += ('* 组件输入初始化\n')
        comments += ('***********************************************************/\n')
        funcEntity = self.cpnSourceInitFuncEntity('vfbI'+name,name,'&%sA' %name)
        comments += self.cpnHeaerAndSourceInitFuncComment('','vfbI'+name,funcEntity,'组件输入初始化')
        comments += ('\n'*1)
        comments += ('/***********************************************************\n')
        comments += ('* 组件输入定义\n')
        comments += ('***********************************************************/\n')
        funcEntity = ('(hvfbI%s cthis, h%s %s){\n' %(name,name,name))
        funcEntity += ('    cthis->%s = %s;\n' %(name,name))
        funcEntity += ('    //TODO\n')
        funcEntity += ('\n    return cthis;\n}')
        comments += self.cpnHeaerAndSourceClassInitFuncComment('vfbI'+name,funcEntity,'组件类初始化函数')
        funcEntity = ('(vfbI%s){\n' %name)
        funcEntity += ('    cthis->init = vfbI%s_init;\n' %name)
        funcEntity += ('    //TODO\n')
        funcEntity += ('\n    return cthis;\n}')
        comments += self.cpnHeaerAndSourceCCFuncComment('vfbI'+name,funcEntity,'组件类构造函数')
        funcEntity = ('(vfbI%s){\n    return OOPC_TRUE;\n}' %name)
        comments += self.cpnHeaerAndSourceCDFuncComment('vfbI'+name,funcEntity,'组件类析构函数')
        comments += ('\n'*1)
        comments += ('/***********************************************************\n')
        comments += ('* 组件输入实例化\n')
        comments += ('***********************************************************/\n')
        comments += ('/*组件输入类实例\n')
        comments += ('***********************************************/\n')
        comments += ('vfbI%s vfbI%sA;\n' %(name,name))
        comments += ('\n'*1)
        return comments
        
    def cpnSourceGenerateCpnInitAndSchComment(self,name):
        '''组件初始化及调度注释'''
        comments = ('/***********************************************************\n')
        comments += ('* 组件初始化\n')
        comments += ('***********************************************************/\n')
        funcEntity = self.cpnSourceInitFuncEntity(name,'vfbO'+name,'&sm%s[0], &vfbO%sA' %(name,name))
        comments += self.cpnHeaerAndSourceInitFuncComment('',name,funcEntity,'组件初始化')
        comments += ('\n'*1)
        comments += ('/***********************************************************\n')
        comments += ('* 组件调度\n')
        comments += ('***********************************************************/\n')
        funcEntity = ('(void){\n    %sA.run(%sA.self);\n}' %(name,name))
        comments += self.cpnHeaerAndSourceSchFuncComment('',name,funcEntity,'组件进行调度')
        return comments 
    def cpnSourceGenerateCpnComment(self,name):
        '''组件定义'''
        comments = ('/***********************************************************\n')
        comments += ('* 组件定义\n')
        comments += ('***********************************************************/\n')
        funcEntity = ('(h%s cthis, hstaAct sm%s, hvfbO%s vfbO%s){\n' %(name,name,name,name))
        funcEntity += ('    cthis->sm%s = sm%s;\n' %(name,name))
        funcEntity += ('    cthis->vfbO%s = vfbO%s;\n' %(name,name))
        funcEntity += ('    //TODO\n')
        funcEntity += ('\n    return cthis;\n}')
        comments += self.cpnHeaerAndSourceClassInitFuncComment(name,funcEntity,'组件类初始化函数')
        #comments += ('\n'*1)
        funcEntity = ('(h%s t){\n' %name)
        funcEntity += ('    SMRE(t->sm%s, t->sm%sRec);\n}' %(name,name))
        comments += self.cpnHeaerAndSourceClassFuncComment(name,'run',funcEntity,'组件运行函数')
        funcEntity = ('(%s){\n' %name)
        funcEntity += ('    cthis->init = %s_init;\n' %name)
        funcEntity += ('    cthis->run = %s_run;\n' %name)
        funcEntity += ('    //TODO\n')
        funcEntity += ('\n    cthis->sm%sRec.next = sm%s_sta_init;\n' %(name,name))
        funcEntity += ('    //TODO\n')
        funcEntity += ('\n    return cthis;\n}')
        comments += self.cpnHeaerAndSourceCCFuncComment(name,funcEntity,'组件类构造函数')
        funcEntity = ('(%s){\n    return OOPC_TRUE;\n}' %name)
        comments += self.cpnHeaerAndSourceCDFuncComment(name,funcEntity,'组件类析构函数')
        comments += ('\n'*1)
        comments += ('/***********************************************************\n')
        comments += ('* 组件异步调度功能函数\n')
        comments += ('***********************************************************/\n')
        comments += ('/*异步调度功能函数\n')
        comments += ('***********************************************/\n')
        comments += ('//void %s_abi_example(void){\n//  //TODO\n//}\n' %name)
        comments += ('\n'*2)
        comments += ('/***********************************************************\n')
        comments += ('* 组件实例化\n')
        comments += ('***********************************************************/\n')
        comments += ('/*组件类实例\n')
        comments += ('***********************************************/\n')
        comments += ('%s %sA;\n' %(name,name))
        comments += ('\n'*1)
        return comments
    
    def cpnSourceInitFuncEntityNoInj(self,initName,outName):
        funcEntity = ("(void){\n")
        funcEntity += ("    int16 rtv = 0;\n\n")
        funcEntity += ("    CNNP(%s, &%sA);\n" %(initName,initName))
        funcEntity += ("    if(OPRS(%sA) != OOPC_NULL){\n" %initName)
        funcEntity += ("        rtv = %sInit();\n    }else{\n        rtv = -1;\n    }\n" %outName)
        funcEntity += ("\n    return rtv;\n}")
        return funcEntity
    def cpnSourceGenerateVfbOcpnComment(self,name):
        '''组件输入定义'''
        comments = ('/***********************************************************\n')
        comments += ('* 组件输出初始化\n')
        comments += ('***********************************************************/\n')
        funcEntity = self.cpnSourceInitFuncEntityNoInj('vfbO'+name,'vfbM'+name)
        comments += self.cpnHeaerAndSourceInitFuncComment('','vfbO'+name,funcEntity,'组件输入初始化')
        comments += ('\n'*1)
        comments += ('/***********************************************************\n')
        comments += ('* 组件输出定义\n')
        comments += ('***********************************************************/\n')
        funcEntity = ('(hvfbO%s cthis){\n' %name)
        funcEntity += ('    cthis->schParam.id = 0;\n')
        funcEntity += ('    cthis->schParam.schTask = %sSch;\n' %name)
        funcEntity += ('    cthis->schParam.startTick = (%s_START_TICK_CFG / CASSCH_TIMER_PRD_CFG);\n' %name.upper())
        funcEntity += ('    cthis->schParam.prdTick = (%s_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);\n' %name.upper())
        funcEntity += ('    //TODO\n')
        funcEntity += ('\n    return cthis;\n}')
        comments += self.cpnHeaerAndSourceClassInitFuncComment('vfbO'+name,funcEntity,'组件类初始化函数')
        funcEntity = ('(vfbO%s){\n' %name)
        funcEntity += ('    cthis->init = vfbO%s_init;\n' %name)
        funcEntity += ('    //TODO\n')
        funcEntity += ('\n    return cthis;\n}')
        comments += self.cpnHeaerAndSourceCCFuncComment('vfbO'+name,funcEntity,'组件类构造函数')
        funcEntity = ('(vfbO%s){\n    return OOPC_TRUE;\n}' %name)
        comments += self.cpnHeaerAndSourceCDFuncComment('vfbO'+name,funcEntity,'组件类析构函数')
        comments += ('\n'*1)
        comments += ('/***********************************************************\n')
        comments += ('* 组件输出实例化\n')
        comments += ('***********************************************************/\n')
        comments += ('/*组件输出类实例\n')
        comments += ('***********************************************/\n')
        comments += ('vfbO%s vfbO%sA;\n' %(name,name))
        comments += ('\n'*1)
        return comments
    
    def cpnSourcevfbMInitFuncEntity(self,name):
        funcEntity = ("(void){\n")
        funcEntity += ("    int16 rtv = 0;\n\n")
        funcEntity += ("    CN(vfbM%s, &vfbM%sA, &vfbO%sA, &vfbIcasSchA);\n" %(name,name,name))
        funcEntity += ("    if(OPRS(vfbM%sA) != OOPC_NULL){\n" %name)
        funcEntity += ("        vfbM%sA.vfbO%s->schParam.id = %s_id_priority_cfg;\n" %(name,name,name))
        funcEntity += ("        vfbM%sA.vfbO%s->schParam.prdTick = (%s_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);\n" %(name,name,name.upper()))
        funcEntity += ("        vfbM%sA.vfbO%s->schParam.startTick = (%s_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);\n" %(name,name,name.upper()))
        funcEntity += ("        vfbM%sA.vfbIcasSchA->addTask(vfbIcasSchA.self,\n" %name)
        funcEntity += ("            vfbM%sA.vfbO%s->schParam.id, vfbM%sA.vfbO%s->schParam.schTask,\n" %(name,name,name,name))
        funcEntity += ("            vfbM%sA.vfbO%s->schParam.prdTick, vfbM%sA.vfbO%s->schParam.startTick)\n" %(name,name,name,name))
        funcEntity += ("\n        rtv = 0;\n    }else{\n        rtv = -1;\n    }\n")
        funcEntity += ("\n    return rtv;\n}")
        return funcEntity
    def cpnSourceGenerateVfbMcpnComment(self,name):
        '''组件输入定义'''
        comments = ('/*组件调度id临时配置，组件实际使用时必须在vbfMCfg.h中配置\n')
        comments += ('***********************************************************/\n')
        comments += ('#define %s_id_priority_cfg   0\n' %name)
        comments += ('\n'*2)
        comments += ('/***********************************************************\n')
        comments += ('* 组件管理初始化\n')
        comments += ('***********************************************************/\n')
        funcEntity = self.cpnSourcevfbMInitFuncEntity(name)
        comments += self.cpnHeaerAndSourceInitFuncComment('','vfbM'+name,funcEntity,'组件管理初始化')
        comments += ('\n'*1)
        comments += ('/***********************************************************\n')
        comments += ('* 组件管理定义\n')
        comments += ('***********************************************************/\n')
        funcEntity = ('(hvfbM%s cthis, hvfbO%s vfbO%s, hvfbIcasSch vfbIcasSch){\n' %(name,name,name))
        funcEntity += ('    cthis->vfbO%s = vfbO%s;\n' %(name,name))
        funcEntity += ('    cthis->vfbIcasSch = vfbIcasSch;\n')
        funcEntity += ('    //TODO\n')
        funcEntity += ('\n    return cthis;\n}')
        comments += self.cpnHeaerAndSourceClassInitFuncComment('vfbM'+name,funcEntity,'组件管理类初始化函数')
        funcEntity = ('(vfbM%s){\n' %name)
        funcEntity += ('    cthis->init = vfbM%s_init;\n' %name)
        funcEntity += ('    //TODO\n')
        funcEntity += ('\n    return cthis;\n}')
        comments += self.cpnHeaerAndSourceCCFuncComment('vfbM'+name,funcEntity,'组件管理类构造函数')
        funcEntity = ('(vfbM%s){\n    return OOPC_TRUE;\n}' %name)
        comments += self.cpnHeaerAndSourceCDFuncComment('vfbM'+name,funcEntity,'组件管理类析构函数')
        comments += ('\n'*1)
        comments += ('/***********************************************************\n')
        comments += ('* 组件输出类接口定义\n')
        comments += ('***********************************************************/\n')
        comments += ('/*组件输出类功能函数\n')
        comments += ('***********************************************/\n')
        comments += ('//void vfbM%s_vfbO%s_example(hvfbO%s t){\n//  //TODO\n//}\n' %(name,name,name))
        comments += ('\n'*2)
        comments += ('/***********************************************************\n')
        comments += ('* 组件管理实例化\n')
        comments += ('***********************************************************/\n')
        comments += ('/*组件管理类实例\n')
        comments += ('***********************************************/\n')
        comments += ('vfbM%s vfbM%sA;\n' %(name,name))
        comments += ('\n'*1)
        return comments
    # ======================================================

    
    # ======================================================
    # 具体文件生成函数
    # ======================================================
    def createSource(self,name):
        fh = open(name+'.c',mode = 'w',encoding=self.__encoding)
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
        fh = open(name+'.h',mode = 'w',encoding=self.__encoding)
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
        
    def createCpnHeader(self,name):
        """组件模块头文件
        
        生成组件对象、组件输入对象、组件输出对象"""
        fh = open(name+'.h',mode = 'w',encoding=self.__encoding)
        self.__fileComments['@brief'] = ':组件%s 输入类、组件类、输出类数据类型声明头文件' %name
        cm = self.generateFileHeadComment(name+'.h')
        self.__fileComments['@brief'] = ':'
        cm += "#ifndef %s_H_\n" %name.upper()
        cm += "#define %s_H_\n" %name.upper()
        cm += ("\n"*1)
        cm += ("#include \"..\\..\\%s_std\\std.h\"\n" %self.__cpnTypeIndex['std']) 
        cm += ("#include \"..\\..\\%s_cas\\casSch\\casSch.h\"\n" %self.__cpnTypeIndex['cas']) 
        cm += ("#include \"%sCfg.h\"\n" %name) 
        cm += ("#include \"%sErrCode.h\"\n" %name)
        cm += ("\n"*1)
        cm += self.cpnHeaderGenerateCpnInitAndSchComment(name)
        cm += ('/***********************************************************\n')
        cm += ('* 组件输入类通用数据类型\n')
        cm += ('***********************************************************/\n')
        cm += ("\n"*2)
        cm += ('/***********************************************************\n')
        cm += ('* 组件输出类通用数据类型\n')
        cm += ('***********************************************************/\n')
        cm += ("\n"*2)
        cm += self.cpnHeaderGenerateVfbOcpnComment(name)
        cm += ("\n"*1)
        cm += self.cpnHeaderGenerateCpnComment(name)
        cm += ("\n"*1)
        cm += self.cpnHeaderGenerateVfbIcpnComment(name)
        cm += ("\n"*1)
        cm += "#endif\n\n"
        cm += self.generateFileEndComment()
        fh.write(cm)
        fh.close()
        
    def createcpnCfgHeader(self,name):
        """组件模块配置文件
        
        生成组件基本的配置参数"""
        cpnlen = len(name)
        fh = open(name+'Cfg.h',mode = 'w',encoding=self.__encoding)
        self.__fileComments['@brief'] = ':组件%s 配置头文件' %name
        cm = self.generateFileHeadComment(name+'Cfg.h')
        self.__fileComments['@brief'] = ':'
        cm += "#ifndef %sCFG_H_\n" %name.upper()
        cm += "#define %sCFG_H_\n" %name.upper()
        cm += ("\n"*1)
        cm += ("/*组件调度参数配置\n")
        cm += ('***********************************************************/\n')
        cm += ("#define %s_PRD_TICK_CFG        10000000.0L    // 任务调度周期配置(ns),10ms\n"  %name.upper())
        cm += ("#define %s_START_TICK_CFG      3000000.0L     // 任务调度启动配置(ns),3ms\n"  %name.upper())
        cm += ("\n"*1)
        cm += "#endif\n\n"
        cm += self.generateFileEndComment()
        fh.write(cm)
        fh.close()
    
    def createcpnErrCodeHeader(self,name):
        """组件模块错误码文件
        
        生成组件内部各部分的错误码"""
        cpnlen = len(name)
        fh = open(name+'ErrCode.h',mode = 'w',encoding=self.__encoding)
        self.__fileComments['@brief'] = ':组件%s 内部各组成部分错误码定义头文件' %name
        cm = self.generateFileHeadComment(name+'ErrCode.h')
        self.__fileComments['@brief'] = ':'
        cm += "#ifndef %sERRCODE_H_\n" %name.upper()
        cm += "#define %sERRCODE_H_\n" %name.upper()
        cm += ("\n"*1)
        cm += ("/*errClassify\n")
        cm += ('************************************************************\n')
        cm += ("* #define EC_EC_cie      0 // communicationInputErr   通信输入错误\n")
        cm += ("* #define EC_EC_coe      1 // communicationOutputErr  通信输出错误\n")
        cm += ("* #define EC_EC_se       2 // schedularErr            任务调度错误\n")
        cm += ("* #define EC_EC_fe       3 // functionErr             功能错误\n")
        cm += ('***********************************************************/\n')
        cm += ("\n"*1)
        cm += ("/*errRanking\n")
        cm += ('************************************************************\n')
        cm += ("* #define EC_ER_ignore   0 // ignore   可忽略\n")
        cm += ("* #define EC_ER_warning  1 // warning  警告\n")
        cm += ("* #define EC_ER_serious  2 // serious  严重错误\n")
        cm += ("* #define EC_ER_fatal    3 // fatal    致命错误\n")
        cm += ('***********************************************************/\n')
        cm += ("\n"*1)
        cm += ("/*errDefine\n")
        idspace = (18-cpnlen) * ' '
        idspace2 = (53+cpnlen) * ' '
        errspace = 27 * ' '
        errspace2 = 8 * ' '
        cm += ('************************************************************************************************************************\n')
        cm += ("*                                | %sPartId |   errCode  |  errClassify  |  errRanking     |\n" %name)
        cm += ('***********************************************************************************************************************/\n')
        cm += ("#define %s_part1_pi%s0%s// 组件部件1\n" %(name,idspace,idspace2))
        cm += ("#define %s_part1_err1%s0%s// EC_EC_cie       EC_ER_warning  // 组件部件1错误1\n" %(name,errspace,errspace2))
        cm += ('/**********************************************************************************************************************/\n')
        cm += ("#define %s_part2_pi%s1%s// 组件部件1\n" %(name,idspace,idspace2))
        cm += ("#define %s_part2_err1%s0%s// EC_EC_cie       EC_ER_warning  // 组件部件1错误1\n" %(name,errspace,errspace2))
        cm += ('/**********************************************************************************************************************/\n')
        cm += ("\n"*1)
        cm += "#endif\n\n"
        cm += self.generateFileEndComment()
        fh.write(cm)
        fh.close()
    
    def createVfbIcpnSource(self,name):
        """组件输入类源文件
        
        生成组件输入类实现方式"""
        fh = open('vfbI'+name+'.c',mode = 'w',encoding=self.__encoding)
        self.__fileComments['@brief'] = ':组件%s 输入类定义' %name
        cm = self.generateFileHeadComment('vfbI'+name+'.c')
        self.__fileComments['@brief'] = ':'
        cm += ("#include \"%s.h\"\n" %name) 
        cm += ("\n"*1)
        cm += self.cpnSourceGenerateVfbIcpnComment(name)
        cm += ("\n"*1)
        cm += self.generateFileEndComment()
        fh.write(cm)
        fh.close()
        
    def createCpnSource(self,name):
        """组件类源文件
        
        生成组件类实现方式"""
        fh = open(name+'.c',mode = 'w',encoding=self.__encoding)
        self.__fileComments['@brief'] = ':组件%s 组件类定义' %name
        cm = self.generateFileHeadComment(name+'.c')
        self.__fileComments['@brief'] = ':'
        cm += ("#include \"%s.h\"\n" %name) 
        cm += ("\n"*1)
        cm += self.cpnSourceGenerateCpnInitAndSchComment(name)
        cm += ("\n"*1)
        cm += ('/***********************************************************\n')
        cm += ('* 组件通用功能函数\n')
        cm += ('***********************************************************/\n')
        cm += ("\n"*2)
        cm += ('/***********************************************************\n')
        cm += ('* 组件状态机\n')
        cm += ('***********************************************************/\n')
        cm += ('/*组件状态机定义\n')
        cm += ('***********************************************/\n')
        cm += ('SMDC(sm%s, SM_%s_STA_LIST);\n' %(name,name.upper()))
        cm += ("\n"*1)
        funcEntity = ('(void *hStaRec){\n')
        funcEntity += ('    hsm%sRec rec = (hsm%sRec)hStaRec;\n' %(name,name))
        funcEntity += ('\n    rec->%s = (void *)&%sA;\n' %(name,name))
        funcEntity += ('    //TODO\n')
        funcEntity += ('\n    rec->next = sm%s_sta_sta1;\n}' %name)
        cm += self.cpnHeaerAndSourceSMFuncComment(name,'init',funcEntity,'sm%s_act_init' %name)
        funcEntity = ('(void *hStaRec){\n    hsm%sRec rec = (hsm%sRec)hStaRec;\n    //TODO\n' %(name,name))
        funcEntity += ('\n    rec->next = sm%s_sta_default;\n}' %name)
        cm += self.cpnHeaerAndSourceSMFuncComment(name,'sta1',funcEntity,'sm%s_act_sta1' %name)
        cm += self.cpnHeaerAndSourceSMFuncComment(name,'sta2',funcEntity,'sm%s_act_sta2' %name)
        cm += self.cpnHeaerAndSourceSMFuncComment(name,'default',funcEntity,'sm%s_act_default' %name)
        cm += ("\n"*1)
        cm += self.cpnSourceGenerateCpnComment(name)
        cm += ("\n"*1)
        cm += self.generateFileEndComment()
        fh.write(cm)
        fh.close()
    
    def createVfbOcpnSource(self,name):
        """组件输出类源文件
        
        生成组件输出类实现方式"""
        fh = open('vfbO'+name+'.c',mode = 'w',encoding=self.__encoding)
        self.__fileComments['@brief'] = ':组件%s 输出类定义' %name
        cm = self.generateFileHeadComment('vfbO'+name+'.c')
        self.__fileComments['@brief'] = ':'
        cm += ("#include \"%s.h\"\n" %name) 
        cm += ("\n"*1)
        cm += self.cpnSourceGenerateVfbOcpnComment(name)
        cm += ("\n"*1)
        cm += self.generateFileEndComment()
        fh.write(cm)
        fh.close()
    
    def createVfbMCpnHeader(self,name):
        """组件管理模块头文件
        
        生成组件管理对象"""
        fh = open('vfbM'+name+'.h',mode = 'w',encoding=self.__encoding)
        self.__fileComments['@brief'] = ':组件%s 管理类数据类型声明' %name
        cm = self.generateFileHeadComment('vfbM'+name+'.h')
        self.__fileComments['@brief'] = ':'
        cm += "#ifndef VFBM%s_H_\n" %name.upper()
        cm += "#define VFBM%s_H_\n" %name.upper()
        cm += ("\n"*1)
        cm += ("#include \"..\\..\\%s_std\\std.h\"\n" %self.__cpnTypeIndex['std']) 
        cm += ("#include \"..\\..\\%s_cas\\casSch\\casSch.h\"\n" %self.__cpnTypeIndex['cas'])
        cm += ("#include \"..\\..\\%s_%s\\%s\\%s.h\"\n" %(self.__cpnTypeIndex[self.__cpnType],self.__cpnType,name,name))
        cm += ("#include \"..\\vfbMCfg.h\"\n")
        cm += ("\n"*1)
        cm += ('/***********************************************************\n')
        cm += ('* 组件管理初始化\n')
        cm += ('***********************************************************/\n')
        cm += self.cpnHeaerAndSourceInitFuncComment('','vfbM'+name,'(void);','组件管理初始化')
        cm += ('\n'*1)
        cm += self.cpnHeaderGenerateVfbMcpnComment(name)
        cm += ("\n"*1)
        cm += "#endif\n\n"
        cm += self.generateFileEndComment()
        fh.write(cm)
        fh.close()
        
    def createVfbMcpnSource(self,name):
        """组件输入类源文件
        
        生成组件输入类实现方式"""
        fh = open('vfbM'+name+'.c',mode = 'w',encoding=self.__encoding)
        self.__fileComments['@brief'] = ':组件%s 管理类定义' %name
        cm = self.generateFileHeadComment('vfbM'+name+'.c')
        self.__fileComments['@brief'] = ':'
        cm += ("#include \"%s.h\"\n" %name) 
        cm += ("\n"*1)
        cm += self.cpnSourceGenerateVfbMcpnComment(name)
        cm += ("\n"*1)
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
        '''默认命令'''
        sys.stderr.write("component generate use default function\n")
    
    def cpnConstructorCommandInit(self):
        '''初始化控制命令'''
        self.__cpnConstructorCommand['std'] = self.bspcpnGenFunc
        self.__cpnConstructorCommand['bm'] = self.bspcpnGenFunc
        self.__cpnConstructorCommand['bsp'] = self.bspcpnGenFunc
        self.__cpnConstructorCommand['abi'] = self.bspcpnGenFunc
        self.__cpnConstructorCommand['cpnInit'] = self.bspcpnGenFunc
        self.__cpnConstructorCommand['cas'] = self.bspcpnGenFunc
        self.__cpnConstructorCommand['cs'] = self.bspcpnGenFunc
        self.__cpnConstructorCommand['cuf'] = self.bspcpnGenFunc
        self.__cpnConstructorCommand['cpc'] = self.bspcpnGenFunc
        self.__cpnConstructorCommand['ccc'] = self.bspcpnGenFunc
        self.__cpnConstructorCommand['vfbM'] = self.bspcpnGenFunc
    
    def cpnFolderExistJudgeAndCreat(self):
        """对组件所有需要的文件进行判断是否存在
        
        1.如果文件夹存在由不会生成相应的组件，存在文件夹则可能存在文件，不应该对存在的文件进行覆盖
        2.如果所有文件夹都不存在，则会生成所有需要的文件夹
        3.所有操作都是切到对应文件夹进行操作之后，再退回到脚本所有文件夹"""
        for cpnIndex in self.__cpnFolder:
            if((self.__cpnFolder[cpnIndex] != ' ')and(self.__cpnFolderExist == 0)):
                if(os.path.exists(self.__cpnTypeIndex[cpnIndex]+'_'+cpnIndex)):
                    os.chdir(self.__cpnTypeIndex[cpnIndex]+'_'+cpnIndex)
                    if(os.path.exists(self.__cpnFolder[cpnIndex])):
                        self.__cpnFolderExist = 1
                        sys.stderr.write("%s reference folder exist, please delete and try again\n" %self.__cpnFolder[cpnIndex])
                    else:
                        os.mkdir(self.__cpnFolder[cpnIndex])
                    os.chdir('..')
                else:
                    os.makedirs(self.__cpnTypeIndex[cpnIndex]+'_'+cpnIndex+'\\'+self.__cpnFolder[cpnIndex])

    def bspcpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder['bsp'] != ' '):
            os.chdir(self.__cpnTypeIndex['bsp']+'_bsp\\'+self.__cpnFolder['bsp'])
            self.createSource('bsp'+self.__cpnType+self.__cpnName)
            self.createHeader('bsp'+self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')
            
    def abicpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder['abi'] != ' '):
            os.chdir(self.__cpnTypeIndex['abi']+'_abi\\'+self.__cpnFolder['abi'])
            self.createSource('abi'+self.__cpnType+self.__cpnName)
            self.createHeader('abi'+self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')    
    
    def cpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder[self.__cpnType] != ' '):
            os.chdir(self.__cpnTypeIndex[self.__cpnType]+'_'+self.__cpnType+'\\'+self.__cpnFolder[self.__cpnType])
            self.createCpnHeader(self.__cpnType+self.__cpnName)
            self.createcpnCfgHeader(self.__cpnType+self.__cpnName)
            self.createcpnErrCodeHeader(self.__cpnType+self.__cpnName)
            self.createVfbIcpnSource(self.__cpnType+self.__cpnName)
            self.createCpnSource(self.__cpnType+self.__cpnName)
            self.createVfbOcpnSource(self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')
    
    def cascpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder['cas'] != ' '):
            os.chdir(self.__cpnTypeIndex['cas']+'_cas\\'+self.__cpnFolder['cas'])
            self.createCpnHeader(self.__cpnType+self.__cpnName)
            self.createcpnCfgHeader(self.__cpnType+self.__cpnName)
            self.createcpnErrCodeHeader(self.__cpnType+self.__cpnName)
            self.createVfbIcpnSource(self.__cpnType+self.__cpnName)
            self.createCpnSource(self.__cpnType+self.__cpnName)
            self.createVfbOcpnSource(self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')
        
    def cscpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder['cs'] != ' '):
            os.chdir(self.__cpnTypeIndex['cs']+'_cs\\'+self.__cpnFolder['cs'])
            self.createCpnHeader(self.__cpnType+self.__cpnName)
            self.createcpnCfgHeader(self.__cpnType+self.__cpnName)
            self.createcpnErrCodeHeader(self.__cpnType+self.__cpnName)
            self.createVfbIcpnSource(self.__cpnType+self.__cpnName)
            self.createCpnSource(self.__cpnType+self.__cpnName)
            self.createVfbOcpnSource(self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')
    
    def cufcpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder['cuf'] != ' '):
            os.chdir(self.__cpnTypeIndex['cuf']+'_cuf\\'+self.__cpnFolder['cuf'])
            self.createCpnHeader(self.__cpnType+self.__cpnName)
            self.createcpnCfgHeader(self.__cpnType+self.__cpnName)
            self.createcpnErrCodeHeader(self.__cpnType+self.__cpnName)
            self.createVfbIcpnSource(self.__cpnType+self.__cpnName)
            self.createCpnSource(self.__cpnType+self.__cpnName)
            self.createVfbOcpnSource(self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')

    def cpccpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder['cpc'] != ' '):
            os.chdir(self.__cpnTypeIndex['cpc']+'_cpc\\'+self.__cpnFolder['cpc'])
            self.createCpnHeader(self.__cpnType+self.__cpnName)
            self.createcpnCfgHeader(self.__cpnType+self.__cpnName)
            self.createcpnErrCodeHeader(self.__cpnType+self.__cpnName)
            self.createVfbIcpnSource(self.__cpnType+self.__cpnName)
            self.createCpnSource(self.__cpnType+self.__cpnName)
            self.createVfbOcpnSource(self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')

    def ccccpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder['ccc'] != ' '):
            os.chdir(self.__cpnTypeIndex['ccc']+'_ccc\\'+self.__cpnFolder['ccc'])
            self.createCpnHeader(self.__cpnType+self.__cpnName)
            self.createcpnCfgHeader(self.__cpnType+self.__cpnName)
            self.createcpnErrCodeHeader(self.__cpnType+self.__cpnName)
            self.createVfbIcpnSource(self.__cpnType+self.__cpnName)
            self.createCpnSource(self.__cpnType+self.__cpnName)
            self.createVfbOcpnSource(self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')

    def vfbMcpnGenFunc(self):
        if(self.__cpnFolderExist == 0)and(self.__cpnFolder['vfbM'] != ' '):
            os.chdir(self.__cpnTypeIndex['vfbM']+'_vfbM\\'+self.__cpnFolder['vfbM'])
            self.createVfbMCpnHeader(self.__cpnType+self.__cpnName)
            self.createVfbMcpnSource(self.__cpnType+self.__cpnName)
            os.chdir('..')
            os.chdir('..')
    # ======================================================
        
        
    def createTemp(self):    
        self.cpnFolderExistJudgeAndCreat()
        for cpnIndex in self.__cpnFolder:
            if(self.__cpnFolder[cpnIndex] != ' '):
                self.__cpnConstructorCommand[cpnIndex]()
        
        
if __name__ == '__main__':
    if len(sys.argv) != 3:
        sys.stderr.write("please input corret parameter\n")
    else:
        cpnType = sys.argv[1]
        cpnName = sys.argv[2]
        cpn = cpnShell(cpnType,cpnName)
        cpn.createTemp()