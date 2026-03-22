                     MSDN context help plugin v. 1.0
                          for FAR manager 1.65+
              copyright (c) 2001, Stanislav V. Mekhanoshin

============================ readme, Russian ===========================

    Этот плагин предназначен  для  вызова  контекстной  помощи  MSDN  из
внутреннего редактора FAR manager'а. Т.е. ориентирован на разработчиков.
Если вам слово MSDN ничего не говорит, то этот плагин не для вас.
    Плагин распространяется на основе лицензии freeware. Используйте  на
свой страх и риск, гарантий нет.
    Для работы плагина необходимо  наличие  FAR  1.65  и  установленного
MSDN'а. Понятие установленного MSDN'а с точки зрения плагина сводится  к
следующему:

    1) наличие hhctrl.ocx (собственно сама инжина HtmlHelp'а)
    2) наличие пути к коллекции MSDN'а в  реестре.  Путь  этот  строится
       следующим образом: в HKEY_LOCAL_MACHINE находится ключ

       SOFTWARE\Microsoft\HTML Help Collections\Developer Collections,
       который содержит в себе значение REG_SZ Language, в  моем  случае
       "0x409",  подключ,  на  который  указывает   Language   ("0x409")
       содержит значение REG_SZ Preferred, в моем случае "0x038494890").
       Его  подключ  с  именем  из  Preferred  ("0x038494890")  содержит
       значение REG_SZ Filename, указывающий на полный путь до коллекции
       MSDN (файл, с расширением .col).

       Если у вас это не так, то я  думаю  что  вам  не  составит  труда
       модифицировать плагин соответствующим образом. Исходные тексты
       прилагаются.

    Для использования удобно назначить в редакторе  макрос  на  ^F1  или
#F1.

============================ readme, English ===========================

    This plugin has to be used  to  call  MSDN  context  help  from  FAR
manager internal editor. I.e. it is oriented primarily on developers. If
You are not familiar with the name "MSDN" that's not for You.
    Plugin is freeware. There is no warranty, use on You own risk.
    To function plugin needs FAR 1.65  or  higher  and  MSDN  installed.
Installed MSDN for the plugin that is:

    1) Must have hhctrl.ocx (HtmlHelp engine itself)
    2) Path to the MSDN collection specified in registry. This path  has
       to be built in following way: in HKEY_LOCAL_MACHINE  there  is  a
       key

       SOFTWARE\Microsoft\HTML Help Collections\Developer Collections,
       which contains the REG_SZ value Language ("0x409"  in  my  case).
       Subkey to which Language  points  to  ("0x409")  contains  REG_SZ
       value Preferred ("0x038494890" in my case). Its subkey  with  the
       name given by Preferred  ("0x038494890")  contains  REG_SZ  value
       Filename pointing to the full pathname  to  the  MSDN  collection
       (that's the file with .col extension).

       If in Your case that's not  so  I  think  that  will  be  not  so
       difficult for You to modify the plugin as You need.  Source  code
       is included.

    That's comfortable to make the editor macros for ^F1 or #F1 to  call
the plugin.

========================================================================
                                             mail-to: rampitec@tu.spb.ru
                                                      FIDO: 2:5030/172.9
