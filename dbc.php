<?php
	$host="localhost:3306";
	$user="root";
	$password ="dm0805"; 
	$db="Luminarias";
	// Create connection
	$conn = new mysqli($host, $user, $password, $db);
	mysqli_select_db($conn,$db);
	// Check connection
	if ($conn->connect_error) {
    		die("Connection failed: " . $conn->connect_error);
	}


?>
