<html>
    <head>
        <title>PHP and MySQL</title>
    </head>
    <body>
        <form method="post" action="<?php echo $_SERVER['PHP_SELF'];?>">
            <?php   
                require 'connection.php';
                $viewName = "";
                $viewRoll = "";
                if($_SERVER['REQUEST_METHOD']=="POST" and isset($_POST['insert'])){
                    insertIn($mysqli);
                }
                else if($_SERVER['REQUEST_METHOD']=="POST" and isset($_POST['viewone'])){
                    viewOne($mysqli);
                }
                else if($_SERVER['REQUEST_METHOD']=="POST" and isset($_POST['viewall'])){
                    viewAll($mysqli);
                }
                function insertIn($mysqli){
                    $roll = $_POST['roll'];
                    $name = $_POST['name'];
                    if($roll != "" and $name != ""){
                        $sql = "INSERT INTO student(roll,student_name) VALUES ($roll, '$name')";
                        $roll = "";
                        $name = "";
                    }
                    if($mysqli->query($sql) === true){
                        echo "<h4>Result:</h4>";
                        echo "Records inserted successfully.";
                    } else{
                        echo "ERROR: Could not able to execute $sql. " . $mysqli->error;
                    }
                }
                function viewOne($mysqli){
                    $rollno = $_POST['rollno'];
                    if($rollno != ""){
                        $sql = "select * from student where roll = $rollno";
                        
                    }
                    if($result = $mysqli -> query($sql)){
                        while($row = $result -> fetch_assoc()){
                            $viewRoll = $row['roll'];
                            $viewName = $row['student_name'];
                        }
                            displayOne($viewRoll,$viewName);
                    }
                }
                function displayOne($viewRoll,$viewName){
                    echo "<h4>Result:</h4>";
                    echo "<table>";
                    echo "<tr>";
                    echo "<td>$viewRoll</td>";
                    echo "<td>$viewName</td>";
                    echo "</tr>";
                    echo "</table>";
                }
                function viewAll($mysqli){
                    $sql = "select * from student";
                    if($result = $mysqli -> query($sql)){
                        echo "<table>";
                        echo "<h4>Result:</h4>";
                        while($row = $result -> fetch_assoc()){
                            $viewRoll = $row['roll'];
                            $viewName = $row['student_name'];
                            echo "<tr>";
                            echo "<td>$viewRoll</td>";
                            echo "<td>$viewName</td>";
                            echo "</tr>";
                        }
                        echo "</table>";
                    }
                }
            ?>
            <div>
            
                <table cellpadding="5">
                    <tr>
                    <hr/>
                        <h4>Insert</h4>
                        <td>
                            Roll no:
                        </td>
                        <td>
                            <input type="text" name="roll">
                        </td>
                    </tr>
                    <tr>
                        <td>
                            Name:
                        </td>
                        <td>
                            <input type="text" name="name">
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <input type="submit" value="Insert" name="insert">
                        </td>
                        <td>
                            <input type="reset" value="Reset">
                        </td>
                    </tr>
                </table>
            </div>
            <hr/>
            <div>
                <table cellpadding="5">
                    <tr>
                        <h4>View</h4>
                            <td>
                                Roll no:
                            </td>
                            <td>
                                <input type="text" name="rollno">
                            </td>
                            <td>
                                <input type="submit" value="View" name="viewone">
                            </td>
                    </tr>
                </table>
            </div>
            <hr/>
            <div>
                <table cellpadding="5">
                    <tr>
                        <h4>View all</h4>
                        <td>
                            <input type="submit" value="View all" name="viewall">
                        </td>
                    </tr>
                </form> 
            </table>            
        </div>
    </body>
</html>