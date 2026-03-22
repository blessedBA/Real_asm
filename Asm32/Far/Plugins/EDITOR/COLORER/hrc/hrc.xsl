<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<xsl:output method="html" encoding="Windows-1251"/>

<xsl:template match="/">
<html>
<head>
<title>hrc script</title>
</head>
<body>
  <div style="font-size:10pt; font-family:verdana, tahoma, andale mono;">
  <xsl:apply-templates/>
  </div>
</body>
</html>
</xsl:template>

<xsl:template match="hrc/include">
<h3>including file
  <a>
   <xsl:attribute name="href"><xsl:value-of select="@name"/></xsl:attribute>
   <xsl:value-of select="@name"/>
  </a>
</h3>
</xsl:template>

<xsl:template match="hrc/define">
region <b><xsl:value-of select="@name"/></b> has value of <b><xsl:value-of select="@value"/></b><br/>
</xsl:template>

<xsl:template match="hrc/type">
<a><xsl:attribute name="name"><xsl:value-of select="@name"/></xsl:attribute></a>
<h2>file type '<xsl:value-of select="@descr"/>'</h2>
name: <b><xsl:value-of select="@name"/></b><br/>
extensions: <b><xsl:value-of select="@exts"/></b><br/>
<blockquote>
  <xsl:apply-templates select="scheme"/>
  <xsl:apply-templates select="load"/>
  <xsl:if test="count(switch) != 0">
  used language switches:<ul>
  <xsl:apply-templates select="switch"/>
  </ul>
  </xsl:if>
</blockquote>
<br/>
</xsl:template>

<xsl:template match="hrc/type/load">
need
  <a>
   <xsl:attribute name="href"><xsl:value-of select="@name"/></xsl:attribute>
   <xsl:value-of select="@name"/>
  </a>
file to load<br/>
</xsl:template>

<xsl:template match="hrc/type/scheme">
uses <b><xsl:value-of select="@name"/></b> as base scheme<br/>
</xsl:template>

<xsl:template match="hrc/type/switch">
  <a>
   <xsl:attribute name="href">#<xsl:value-of select="@type"/></xsl:attribute>
   <xsl:value-of select="@type"/>
  </a>
  on match
<b><xsl:value-of select="@match"/></b><br/>
</xsl:template>

<!-- scheme defines -->

<xsl:template match="hrc/scheme">
<h2>scheme <b><xsl:value-of select="@name"/></b></h2>
<blockquote>
  <xsl:apply-templates/>
</blockquote>
<br/>
</xsl:template>

<xsl:template match="hrc/scheme/inherit">
inherits <b><xsl:value-of select="@scheme"/></b> scheme<br/>
</xsl:template>

<xsl:template match="hrc/scheme/regexp">
regexp <b><xsl:value-of select="@match"/></b><br/>
</xsl:template>

<xsl:template match="hrc/scheme/block">
switches into scheme <b><xsl:value-of select="@scheme"/></b><br/>
</xsl:template>

<xsl:template match="hrc/scheme/keywords">
uses keywords <b><xsl:value-of select="@region"/></b><br/>
</xsl:template>

</xsl:stylesheet>
