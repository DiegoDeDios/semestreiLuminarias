<?php
 include 'dbc.php';
 $id = $_POST["id"];
 $text = $_POST["text"];
 $column_name = $_POST["column_name"];
 $sql = "UPDATE lampStatus SET ".$column_name."='".$text."' WHERE idStatus='".$id."'";
 if(mysqli_query($conn, $sql))
 {
      echo 'Data Updated';
 }
 ?>
