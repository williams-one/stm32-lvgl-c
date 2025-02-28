cd stm32-lvgl-c

python3 lvgl/scripts/LVGLImage.py hal_stm_lvgl/image/background.png -o hal_stm_lvgl/images --ofmt C --cf I8
python3 lvgl/scripts/LVGLImage.py hal_stm_lvgl/image/background.png -o hal_stm_lvgl/images --ofmt C --cf RGB565
python3 lvgl/scripts/LVGLImage.py hal_stm_lvgl/image/background.png -o hal_stm_lvgl/images --ofmt C --cf ARGB8888

python3 lvgl/scripts/LVGLImage.py .\hal_stm_lvgl\images\external_1_800x480.png -o hal_stm_lvgl\images --ofmt C --cf ARGB8888
python3 lvgl/scripts/LVGLImage.py .\hal_stm_lvgl\images\external_2_800x480.png -o hal_stm_lvgl\images --ofmt C --cf ARGB8888
python3 lvgl/scripts/LVGLImage.py .\hal_stm_lvgl\images\internal_1_800x480.png -o hal_stm_lvgl\images --ofmt C --cf ARGB8888
python3 lvgl/scripts/LVGLImage.py .\hal_stm_lvgl\images\internal_2_800x480.png -o hal_stm_lvgl\images --ofmt C --cf ARGB8888

python3 lvgl/scripts/LVGLImage.py .\hal_stm_lvgl\images\external_1_800x480_dither.png -o hal_stm_lvgl\images --ofmt C --cf ARGB8888
python3 lvgl/scripts/LVGLImage.py .\hal_stm_lvgl\images\external_2_800x480_dither.png -o hal_stm_lvgl\images --ofmt C --cf ARGB8888
python3 lvgl/scripts/LVGLImage.py .\hal_stm_lvgl\images\internal_1_800x480_dither.png -o hal_stm_lvgl\images --ofmt C --cf ARGB8888
python3 lvgl/scripts/LVGLImage.py .\hal_stm_lvgl\images\internal_2_800x480_dither.png -o hal_stm_lvgl\images --ofmt C --cf ARGB8888

C:\projects\ide-files\Files\Tools\lvgl_image_converter\lvgl_image_converter.exe .\hal_stm_lvgl\images\image_1_800x480_tsc6.png -o hal_stm_lvgl\images --ofmt C --cf NEMA_TSC6  --nemagfx
C:\projects\ide-files\Files\Tools\lvgl_image_converter\lvgl_image_converter.exe .\hal_stm_lvgl\images\image_2_800x480_tsc6a.png -o hal_stm_lvgl\images --ofmt C --cf NEMA_TSC6A  --nemagfx
C:\projects\ide-files\Files\Tools\lvgl_image_converter\lvgl_image_converter.exe .\hal_stm_lvgl\images\image_3_800x480_i8.png -o hal_stm_lvgl\images --ofmt C --cf I8  --nemagfx

C:\projects\ide-files\Files\Tools\lvgl_image_converter\lvgl_image_converter.exe .\hal_stm_lvgl\images\irinox.png -o hal_stm_lvgl\images --ofmt C --cf ARGB8888 --nemagfx
C:\projects\ide-files\Files\Tools\lvgl_image_converter\lvgl_image_converter.exe .\hal_stm_lvgl\images\irinox_alpha_argb8888.png -o hal_stm_lvgl\images --ofmt C --cf ARGB8888  --nemagfx
C:\projects\ide-files\Files\Tools\lvgl_image_converter\lvgl_image_converter.exe .\hal_stm_lvgl\images\irinox_alpha_tsc6a.png -o hal_stm_lvgl\images --ofmt C --cf NEMA_TSC6A  --nemagfx
C:\projects\ide-files\Files\Tools\lvgl_image_converter\lvgl_image_converter.exe .\hal_stm_lvgl\images\irinox_alpha_i8.png -o hal_stm_lvgl\images --ofmt C --cf I8  --nemagfx

C:\projects\ide-files\Files\Tools\lvgl_image_converter\lvgl_image_converter.exe .\hal_stm_lvgl\images\image_1_800x480_tsc6.png -o hal_stm_lvgl\images --ofmt C --cf I8 --nemagfx
C:\projects\ide-files\Files\Tools\lvgl_image_converter\lvgl_image_converter.exe .\hal_stm_lvgl\images\image_3_800x480_i8.png -o hal_stm_lvgl\images --ofmt C --cf I8 --nemagfx
C:\projects\ide-files\Files\Tools\lvgl_image_converter\lvgl_image_converter.exe .\hal_stm_lvgl\images\image_1_800x480_tsc6.png -o hal_stm_lvgl\images --ofmt C --cf I8 --nemagfx --memorysection ExtFlashSection
C:\projects\ide-files\Files\Tools\lvgl_image_converter\lvgl_image_converter.exe .\hal_stm_lvgl\images\image_2_800x480_tsc6a.png -o hal_stm_lvgl\images --ofmt C --cf I8 --nemagfx --memorysection ExtFlashSection
C:\projects\ide-files\Files\Tools\lvgl_image_converter\lvgl_image_converter.exe .\hal_stm_lvgl\images\image_3_800x480_i8.png -o hal_stm_lvgl\images --ofmt C --cf I8 --nemagfx --memorysection ExtFlashSection

<<<<<<< Updated upstream
C:\projects\ide-files\Files\Tools\lvgl_image_converter\lvgl_image_converter.exe .\hal_stm_lvgl\images\image_1_800x480_tsc6.png -o hal_stm_lvgl\images --ofmt C --cf NEMA_TSC6 --nemagfx --memorysection ExtFlashSection
C:\projects\ide-files\Files\Tools\lvgl_image_converter\lvgl_image_converter.exe .\hal_stm_lvgl\images\image_2_800x480_tsc6a.png -o hal_stm_lvgl\images --ofmt C --cf NEMA_TSC6A --nemagfx --memorysection ExtFlashSection
C:\projects\ide-files\Files\Tools\lvgl_image_converter\lvgl_image_converter.exe .\hal_stm_lvgl\images\image_3_800x480_i8.png -o hal_stm_lvgl\images --ofmt C --cf I8 --nemagfx --memorysection ExtFlashSection
=======
C:/tools/lvgl_image_converter/lvgl_image_converter.exe .\hal_stm_lvgl\images\image_1_800x480_tsc6.png -o hal_stm_lvgl\images --ofmt C --cf NEMA_TSC6 --nemagfx --memorysection ExtFlashSection
C:/tools/lvgl_image_converter/lvgl_image_converter.exe .\hal_stm_lvgl\images\image_2_800x480_tsc6a.png -o hal_stm_lvgl\images --ofmt C --cf NEMA_TSC6A --nemagfx --memorysection ExtFlashSection
C:/tools/lvgl_image_converter/lvgl_image_converter.exe .\hal_stm_lvgl\images\image_3_800x480_i8.png -o hal_stm_lvgl\images --ofmt C --cf I8 --nemagfx --memorysection ExtFlashSection
C:/tools/lvgl_image_converter/lvgl_image_converter.exe .\hal_stm_lvgl\images\image_1_800x480_argb8888.png -o hal_stm_lvgl\images --ofmt C --cf ARGB8888 --nemagfx --memorysection ExtFlashSection

C:/tools/lvgl_image_converter/lvgl_image_converter.exe .\hal_stm_lvgl\images\image_1_480x272_tsc6.png -o hal_stm_lvgl\images --ofmt C --cf NEMA_TSC6 --nemagfx --memorysection ExtFlashSection
C:/tools/lvgl_image_converter/lvgl_image_converter.exe .\hal_stm_lvgl\images\image_2_480x272_tsc6a.png -o hal_stm_lvgl\images --ofmt C --cf NEMA_TSC6A --nemagfx --memorysection ExtFlashSection
C:/tools/lvgl_image_converter/lvgl_image_converter.exe .\hal_stm_lvgl\images\image_3_480x272_i8.png -o hal_stm_lvgl\images --ofmt C --cf I8 --nemagfx --memorysection ExtFlashSection
C:/tools/lvgl_image_converter/lvgl_image_converter.exe .\hal_stm_lvgl\images\image_1_480x272_argb8888.png -o hal_stm_lvgl\images --ofmt C --cf ARGB8888 --nemagfx --memorysection ExtFlashSection
>>>>>>> Stashed changes
