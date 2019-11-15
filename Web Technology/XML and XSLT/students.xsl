<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <html>
       <body>
            <h1>Students</h1>
            <table border="1" cellpadding = "5" cellspacing = "0">
              <tr  bgcolor = "grey">
                 <th>Roll No</th>
                 <th>Name</th>
                 <th>Subject</th>
                 <th>Marks</th>
                 <th>Grade</th>
              </tr>
             <xsl:for-each select="class/student">
              <tr>
                 <td><xsl:value-of select="@roll"/></td>
                 <td><xsl:value-of select="name"/></td>
                 <td><xsl:value-of select="subject"/></td>
                 <td><xsl:value-of select="marks"/></td>
                 <td>
                 <xsl:choose>
                    <xsl:when test= "marks>59"> First Class
                    </xsl:when>   
                    <xsl:when test= "marks>39"> Second Class
                    </xsl:when>   
                    <xsl:otherwise> Fail
                    </xsl:otherwise>
                 </xsl:choose>
                 </td>
              </tr>
             </xsl:for-each>
            </table>
       </body>
    </html>     
  </xsl:template>
</xsl:stylesheet>
