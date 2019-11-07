CREATE TABLE EMP3 (
  ID mediumint AUTO_INCREMENT,
  NAME varchar(255) default NULL,
  ADDRESS varchar(255),
  PIN varchar(10) default NULL,
  PRIMARY KEY (ID)
) AUTO_INCREMENT=1;

INSERT INTO EMP3(ID,NAME,ADDRESS,PIN) VALUES (1,"Alexis","Cagnes-sur-Mer","3122"),(2,"Cameron","Stranraer","9232"),(3,"Kato","Portland","82562"),(4,"Justine","Stranraer","YY4 0YA"),(5,"Tyler","Estevan","2710"),(6,"Timon","Boise","11296"),(7,"Clark","Adelaide","56-608"),(8,"Lavinia","Thionville","78-367"),(9,"Guinevere","Windsor","4082"),(10,"Shana","Patna","16152");

SELECT * FROM EMP3;

CREATE TABLE EMP4 (
  ID mediumint AUTO_INCREMENT,
  NAME varchar(255) default NULL,
  ADDRESS varchar(255),
  PIN varchar(10) default NULL,
  PRIMARY KEY (ID)
) AUTO_INCREMENT=1;

INSERT INTO EMP4 (ID,NAME,ADDRESS,PIN) VALUES (1,"Olivia","Nicolosi","65136"),(2,"Brenden","Aparecida de Goiânia","8629"),(3,"Neil","Stranraer","10809-592"),(4,"Yolanda","Hamoir","30959"),(5,"Brynne","Bois-de-Villers","2725"),(6,"Rigel","Saint-GŽry","12819"),(7,"Hedy","Anthisnes","GQ7 7FW"),(8,"Blake","Grand Rapids","31919"),(9,"Heather","Villar Pellice","P85 0IJ"),(10,"Rana","Sluis","50233");

SELECT * FROM EMP3 INNER JOIN EMP4 ON EMP3.ID=EMP4.ID WHERE EMP3.ADDRESS="Stranraer";

SELECT * FROM EMP3 LEFT JOIN EMP4 ON EMP3.ID=EMP4.ID WHERE EMP3.ADDRESS="Stranraer";

SELECT * FROM EMP3 RIGHT JOIN EMP4 ON EMP3.ID=EMP4.ID WHERE EMP3.ADDRESS="Stranraer";

ALTER TABLE EMP3 ADD SALARY INT(10);

UPDATE EMP3 SET SALARY=5200 WHERE ID=1;
UPDATE EMP3 SET SALARY=200 WHERE ID=2;
UPDATE EMP3 SET SALARY=8200 WHERE ID=3;
UPDATE EMP3 SET SALARY=8600 WHERE ID=4;
UPDATE EMP3 SET SALARY=8600 WHERE ID=5;
UPDATE EMP3 SET SALARY=860 WHERE ID=6;
UPDATE EMP3 SET SALARY=860 WHERE ID=7;

SELECT ID, NAME, SALARY FROM EMP3 WHERE SALARY > (SELECT SALARY FROM EMP3 WHERE NAME="Alexis");
 