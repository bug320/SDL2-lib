# 很重要

如果在电脑上的IDE（如 code:block），修改 Canvas.h 文件中的宏定义`SDL_OK`值改为`_PC` ，如果是在 手机上的IDE（如 C4driod），则修改为 `_PE`

 原因是SDL_Init()函数的返回值问题。
