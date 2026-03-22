WLX2FAR версия 0.1.6

Предупреждение: Плагин работает только в WindowsNT, Windows 2000, Windows XP, Windows 2003

Данный плагин предназначен для поддержки TotalCommander WLX
плагинов в FARе. Данное средство поддерживает только "настоящие"
WLX плагины. Под настоящими понимаются те, которые честно создают
навое окно, а не обманывают листер, подгружая процесс.

Установка:
1) Создайте каталог wlx2far в директории с плагинами FARа (c:\Far\Plugins)
2) Скопируйте содержимое архива в этот каталог
3) Перезапустите FAR
4) Запустите wlx2far и добавьте wlx плугины.
5) При желании воспользуйтесь макросами (необходимо повесить wlx2far на
   клавишу 'G' или подкорректировать макросы) в файле wlx2far.reg

Режим работы:
1) В виде листера с множеством закладками который вызывается из командной
   строки с параметрами
2) В виде панелей быстрого просмотра

Пополнение базы WLX плагинов:
Пополнение можно осуществлять вручную редактируя wlx2far.ini или из
меню плагина. При редактировании файла вручную необходимо соблюдать
осторожность - формат записей должен быть верным, иначе все может упасть.
Формат записей для WLX плагинов следующий:

Hotkey1 - Plugin alias1 ? Plugin name1 ? Plugin mask1
Hotkey2 - Plugin alias2 ? Plugin name2 ? Plugin mask2
..............................................
HotkeyN - Plugin aliasN ? Plugin nameN ? Plugin maskN

где: HotkeyN       - горячая клавиша плагина в меню wlx2far. Если пробел то
                     горячей клавиши нету.
     Plugin aliasN - Краткое название плагина.
     Plugin nameN  - имя файла плагина. Может быть полным или относительным
                     (относительно %PATH%).
     Plugin maskN  - маска файлов которые обрабатываются по умолчанию. Имеет
                     вид обычного списка масок FARа, разделенных запятой.
                     Использование масок целесообразно при быстром просмотре,
                     поскольку в нем не работают ассоциации. Открытие же листера
                     инициируется командной строкой и соответственно может быть
                     вызвано посредством использования ассоциации файлов FARа.

Пример файла wlx2far.ini:
A - IEView ? Plugins\IEView\IEView.wlx ? *.htm,*.html,*.shtml,*.txt,*.plg,*.mht,*.xml,*.xsl
  - MMedia ? Plugins\MMedia\MMedia.wlx ? *.avi,*.mp3,*.mpg

Управление плагином:
Управление осуществляется либо с меню плагинов FARа, либо посредством командной строки.
Рекомендуется использование макросов из wlx2far.reg

Управление из меню плагинов:
1     - Показать/Скрыть панель быстрого просмотра для текущего файла на активной панели FARа
2     - Перевести фокус в панель быстрого просмотра
3     - Обновить содержимое панели быстрого просмотра для нового текущего файла
4     - Открыть новую закладку в листере для текущего файла на активной панели FARа
5     - Показать листер
6     - Скрыть листер
7     - Поиск новых wlx плагинов
Ins   - Добавить новый WLX плагин (можно дополнительно задать горячую клавишу и маску файлов
        по умолчанию)
Del   - Удалить текущий WLX плагин
F4    - Изменить настройки текущего WXL плагина (горячую клавишу,маску файлов по умолчанию)
Enter - Открыть в листере новую закладку для текущего WLX плагина с заданными параметрами.
        В качестве параметров обычно выступает имя файла, но может и что-то еще. Например
        в IEView можно передать URL (www.farmanager.com)

Управление из командной строки:
wlx:Arguments                                  - открыть новую закладку в листере с автоматическим выбором
                                                 плагина для аргументамов Arguments. Запуск проводится в
                                                 текущей папке.
wlx2far:search Path                            - поиск новых WLX плагинов в папке Path
wlx2far:plugin_install PluginName PluginFileName PluginMask - установить новый WLX плагин с именем
                                                              PluginName, с именем файла PluginFileName и
                                                              маской по умолчанию PluginMask
wlx2far:plugin_uninstall PluginName            - удалить WLX плагин с именем PluginName
wlx2far:lister_open PluginName Arguments       - открыть новую закладку в листере для плагина
                                                 PluginName с аргументами Arguments. Если имя
                                                 плагина равно '?', то выбирается первый подходящий
                                                 плагина по маске с аргументами Arguments.
wlx2far:lister_show                            - показать листер
wlx2far:lister_hide                            - скрыть листер
wlx2far:leftqviewer_open PluginName Arguments  - открыть левую панель быстрого просмотра для плагина
                                                 PluginName с аргументами Arguments. Если имя
                                                 плагина равно '?', то выбирается первый подходящий
                                                 плагина по маске с аргументами Arguments.
wlx2far:rightqviewer_open PluginName Arguments - открыть правую панель быстрого просмотра для плагина
                                                 PluginName с аргументами Arguments. Если имя
                                                 плагина равно '?', то выбирается первый подходящий
                                                 плагина по маске с аргументами Arguments.
wlx2far:leftqviewer_focus                      - перевести фокус на левую панель быстрого просмотра
wlx2far:rightqviewer_focus                     - перевести фокус на правую панель быстрого просмотра
wlx2far:leftqviewer_close                      - закрыть левую панель быстрого просмотра
wlx2far:rightqviewer_close                     - закрыть правую панель быстрого просмотра

Управление в режиме быстрого просмотра:
Все клавиши управления находятся в файле wlx2far.keys.ini

Проверенные WLX плагины:
 3DMax
 ActiveSnapView
 AmpView 1.0
 ANSI
 AnyTag
 ArchView
 CADView
 Calendar
 CDRView
 DBFView
 DMFView
 DSView
 Dvi
 Eml
 EventLog
 Excellence
 Factory
 FileInfo
 Filter
 Font
 GDBView
 GDBViewer
 Ghost
 GisLister
 ICLView
 IEView
 Imagine
 IniEd
 JccView
 ListDoc
 MD2wlx
 MDLViewer
 MMedia
 MPlayer
 NFOView
 Office
 OOViewer
 OriginView
 PDBView
 PDFView
 PEViewer
 PictureViewer
 Playlist
 Putty
 ruDwgPreview
 SciLister
 SGViewer
 SolidWorks
 Sudoku
 SWFLst
 SWFView
 SyntaxColorizer
 SynUs
 TTFViewer
 TxQuickView
 URLView
 VisualDirSize
 WaveView
 wcpfrep
 WebBrowser
 WebView
 WiseTracker
 WSZView
 xBaseView

Информация об авторе и контакты:
ФИО   - Шинкаренко Иван Сергеевич aka 4ekucT
email - at 4enet.by / 4ekucT
ICQ   - 674333
www   - www.depth.belmt.com
