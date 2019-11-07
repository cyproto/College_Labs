CREATE TABLE EMP1 (
  ID mediumint AUTO_INCREMENT,
  NAME varchar(255) default NULL,
  ADDRESS varchar(255),
  PIN varchar(10) default NULL,
  PRIMARY KEY (ID)
) AUTO_INCREMENT=1;

INSERT INTO EMP1(ID,NAME,ADDRESS,PIN) VALUES (1,"Alexis","Cagnes-sur-Mer","3122"),(2,"Cameron","Stranraer","9232"),(3,"Kato","Portland","82562"),(4,"Justine","Tramutola","YY4 0YA"),(5,"Tyler","Estevan","2710"),(6,"Timon","Boise","11296"),(7,"Clark","Adelaide","56-608"),(8,"Lavinia","Thionville","78-367"),(9,"Guinevere","Windsor","4082"),(10,"Shana","Patna","16152");

SELECT * FROM EMP1;

CREATE TABLE EMP2 (
  ID mediumint AUTO_INCREMENT,
  NAME varchar(255) default NULL,
  ADDRESS varchar(255),
  PIN varchar(10) default NULL,
  PRIMARY KEY (ID)
) AUTO_INCREMENT=1;

INSERT INTO EMP2 (ID,NAME,ADDRESS,PIN) VALUES (1,"Olivia","Nicolosi","65136"),(2,"Brenden","Aparecida de Goiânia","8629"),(3,"Neil","Falciano del Massico","10809-592"),(4,"Yolanda","Hamoir","30959"),(5,"Brynne","Bois-de-Villers","2725"),(6,"Rigel","Saint-GŽry","12819"),(7,"Hedy","Anthisnes","GQ7 7FW"),(8,"Blake","Grand Rapids","31919"),(9,"Heather","Villar Pellice","P85 0IJ"),(10,"Rana","Sluis","50233");

SELECT * FROM EMP2;

SELECT A.ID, A.NAME, B.PIN FROM EMP1 A, EMP2 B WHERE A.NAME=B.NAME;

SELECT * FROM EMP1 UNION SELECT * FROM EMP2;

CREATE VIEW EMP_VIEW AS SELECT NAME, ADDRESS FROM EMP2;

SELECT * FROM EMP_VIEW;

UPDATE EMP_VIEW SET NAME="ABC" WHERE ADDRESS="Nicolosi";

DROP VIEW EMP_VIEW;

