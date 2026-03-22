function determineBrowser() {

  var ua, s, i;

  this.isIE    = false;  // Internet Explorer
  this.isOP    = false;  // Opera
  this.isNS    = false;  // Netscape
  this.version = null;

  ua = navigator.userAgent;

  s = "Opera";
  if ((i = ua.indexOf(s)) >= 0) {
    this.isOP = true;
    this.version = parseFloat(ua.substr(i + s.length));
    return;
  }

  s = "Netscape6/";
  if ((i = ua.indexOf(s)) >= 0) {
    this.isNS = true;
    this.version = parseFloat(ua.substr(i + s.length));
    return;
  }

  // Treat any other "Gecko" browser as Netscape 6.1.

  s = "Gecko";
  if ((i = ua.indexOf(s)) >= 0) {
    this.isNS = true;
    this.version = 6.1;
    return;
  }

  s = "MSIE";
  if ((i = ua.indexOf(s))) {
    this.isIE = true;
    this.version = parseFloat(ua.substr(i + s.length));
    return;
  }
}

var browser = new determineBrowser();

// Capture mouse over on page to close menu
if (browser.isIE) {
  document.onmouseover = pageMouseover;
  document.onkeydown = pageKeyDown;
} else {
  document.addEventListener("mouseover", pageMouseover, true);
  document.addEventListener("keydown", pageKeyDown, true);
}

function getParent(node, parent_name, parent_class) {
  while (node != null) {
    if (node.tagName != null && node.tagName == parent_name &&
        hasClassName(node, parent_class))
      return node;
    node = node.parentNode;
  }
  return node;
}

function hasClassName(element, element_class) {
  var i, list;
  list = element.className.split(" ");
  for (i = 0; i < list.length; i++)
    if (list[i] == element_class)
      return true;
  return false;
}

function addClassName(element, element_class) {
	element.className += " " + element_class;
}

function removeClassName(element, element_class) {

  var i, curList, newList;

  if (element.className == null)
    return;

  newList = new Array();
  curList = element.className.split(" ");
  for (i = 0; i < curList.length; i++)
    if (curList[i] != element_class)
      newList.push(curList[i]);
  element.className = newList.join(" ");
}

function getPageOffsetLeft(element) {
  var x;

  x = element.offsetLeft;

  if (element.offsetParent != null && element.offsetParent.style.position != "relative")
    x += getPageOffsetLeft(element.offsetParent);

  return x;
}

function getPageOffsetTop(element) {
  var y;

  y = element.offsetTop;

  if (element.offsetParent != null && element.offsetParent.style.position != "relative")
    y += getPageOffsetTop(element.offsetParent);

  return y;
}

function showMenu(button) {

  var x, y;

  button.className += " nav_active";

  x = getPageOffsetLeft(button);
  y = getPageOffsetTop(button) + button.offsetHeight;

  button.menu.style.left = x + "px";
  button.menu.style.top  = y + "px";
  button.menu.style.visibility = "visible";
}

function hideMenu(button) {
  removeClassName(button, "nav_active");
  if (button.menu != null) {
    button.menu.style.visibility = "hidden";
  }
}

var activeButton = null;

function buttonMouseover(event, menuId) {
  var button;

  if (browser.isIE) {
    button = window.event.srcElement;
    // Find the actual cell
    button = getParent(button, "TD", "nav_cell");
  } else
    button = event.currentTarget;

  button.blur();
  
  if(activeButton == button && browser.isIE){
  	return;
  }
  
  if (button.menu == null) {
    button.menu = document.getElementById(menuId);
  }

  if (activeButton != null) {
    hideMenu(activeButton);
  }

  if (button != activeButton) {
    showMenu(button);
    activeButton = button;
  }
  else
    activeButton = null;

  return false;
}

function pageMouseover(event) {

  var el;

  if (activeButton == null)
    return;

  if (browser.isIE) {
    el = window.event.srcElement;
  } else
    el = (event.target.tagName ? event.target : event.target.parentNode);
  
  if((activeButton == el || getParent(el,"TD","nav_cell")== activeButton)&& browser.isIE){
  	return;
  }
    
  if (getParent(el, "DIV", "nav_menu") == null) {
    hideMenu(activeButton);
    activeButton = null;
  }
}

function pageKeyDown(event) {
	if(activeButton != null && event.keyCode == '27') {
		hideMenu(activeButton);
		activeButton = null;
	}
}

function buttonMousedown(event, menuId) {
  var button;

  if (browser.isIE)
    button = window.event.srcElement;
  else
    button = event.currentTarget;

  button.blur();

  if (button.menu == null) {
    button.menu = document.getElementById(menuId);
  }

  if (button.menu.style.display == "") {
    button.menu.style.display = "none";
	addClassName(button, "collapsed");
  }
  else {
    button.menu.style.display = "";
	removeClassName(button, "collapsed");
  }
  return false;
}