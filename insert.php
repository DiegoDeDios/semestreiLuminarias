<?php
 include 'dbc.php';
 $sql = "INSERT INTO lampStatus VALUES('".$_POST["ID"]."', '".$_POST["MAC"]."','".$_POST["IP"]."', '".$_POST["Volt"]."', '".$_POST["Status"]."',now())";
 if(mysqli_query($conn, $sql))
 {
      echo 'Data Inserted';
 }
 ?>