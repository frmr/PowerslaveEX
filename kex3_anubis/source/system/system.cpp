//
// Copyright(C) 2014-2015 Samuel Villarreal
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//      Base System API
//

#include "kexlib.h"

//
// quit
//

COMMAND(quit)
{
    kex::cSystem->Shutdown();
}

//
// kexSystem::kexSystem
//

kexSystem::kexSystem(void)
{
    this->bShuttingDown = false;
}

//
// kexSystem::GetWindowFlags
//

int kexSystem::GetWindowFlags(void)
{
    return 0;
}

//
// kexSystem::Log
//

void kexSystem::Log(const char *fmt, ...)
{
}

//
// kexSystem::GetWindowTitle
//

const char *kexSystem::GetWindowTitle(void)
{
    return NULL;
}

//
// kexSystem::SetWindowTitle
//

void kexSystem::SetWindowTitle(const char *string)
{
}

//
// kexSystem::SetWindowGrab
//

void kexSystem::SetWindowGrab(const bool bEnable)
{
}

//
// kexSystem::WarpMouseToCenter
//

void kexSystem::WarpMouseToCenter(void)
{
}

//
// kexSystem::GetProcAddress
//

void *kexSystem::GetProcAddress(const char *proc)
{
    return NULL;
}

//
// kexSystem::CheckParam
//

int kexSystem::CheckParam(const char *check)
{
    for(int i = 1; i < argc; i++)
    {
        if(!kexStr::Compare(check, argv[i]))
        {
            return i;
        }
    }

    return 0;
}

//
// kexSystem::ReadConfigFile
//

void kexSystem::ReadConfigFile(const char *file)
{
    char *buffer;
    int len;
    
    len = kex::cPakFiles->OpenExternalFile(file, (byte**)(&buffer));
    
    if(len == -1)
    {
        Warning("Warning: %s not found\n", file);
        return;
    }
    
    kex::cCommands->Execute(buffer);
    Mem_Free(buffer);
}

//
// kexSystem::WriteConfigFile
//

void kexSystem::WriteConfigFile(void)
{
    extern kexCvar cvarBasePath;
    kexStr str(kexStr::Format("%s\\config.cfg", cvarBasePath.GetValue()));
    str.NormalizeSlashes();
    
    FILE *f = fopen(str.c_str(), "w");
    
    if(f)
    {
        kex::cActions->WriteBindings(f);
        kex::cCvars->WriteToFile(f);
        fclose(f);
    }
}

//
// kexSystem::Printf
//

void kexSystem::Printf(const char *string, ...)
{
}

//
// kexSystem::CPrintf
//

void kexSystem::CPrintf(rcolor color, const char *string, ...)
{
}

//
// kexSystem::Warning
//

void kexSystem::Warning(const char *string, ...)
{
}

//
// kexSystem::DPrintf
//

void kexSystem::DPrintf(const char *string, ...)
{
}

//
// kexSystem::Error
//

void kexSystem::Error(const char* string, ...)
{
}

//
// kexSystem::GetBaseDirectory
//

const char *kexSystem::GetBaseDirectory(void)
{
    return NULL;
}