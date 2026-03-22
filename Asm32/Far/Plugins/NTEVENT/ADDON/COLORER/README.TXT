=== English
0. Make sure you have "Colorer forever" plugin properly installed.
1. Create folder Colorer\hrc\_addons.
2. Copy evtinfo.hrc to Colorer\hrc\_addons.
3. Add following lines into colorer.hrc:

  <type descr="Events" name="evt" exts="/\.info$/i">
    <load name="_addons\evtinfo.hrc"/>
    <scheme name="EvtInfo"/>
  </type>


=== Russian
0. Удостоверьтесь в том, что у Вас установлен плагин "Colorer forever".
1. Создайте папку Colorer\hrc\_addons.
2. Скопируйте evtinfor.hrc в папку Colorer\hrc\_addons.
3. Добавьте следующие строки в colorer.hrc:

  <type descr="События" name="evt" exts="/\.info$/i">
    <load name="_addons\evtinfor.hrc"/>
    <scheme name="EvtInfo"/>
  </type>
