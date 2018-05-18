#!/usr/bin/env python3

import os
import shutil

os.chdir('build')
if os.name == 'posix':
    os.system('cmake ..')
    os.system('make')
    os.system('./test/main_test')
if os.name == 'nt':
    os.system('cmake .. -G "Visual Studio 15 Win64')
    os.system('msbuild fgrep.sln')
    shutil.copy('src/Debug/libfgrep.dll', 'test/Debug/libfgrep.dll')
    os.chdir('test/Debug')
    os.system('main_test.exe')
