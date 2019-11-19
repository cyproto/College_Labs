<?php
	//mysqli("host","user","pass","database");
	$mysqli = new mysqli("localhost", "root", "yash","abc");
    if($mysqli -> connect_error){
        echo "Failed to connect: " . $mysqli -> connect_error;
        exit();
    }
?>