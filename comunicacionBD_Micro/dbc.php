
<?php $servername = "localhost:3306";
$username = "root";
$password = "dm0805";
$dbname = "Semestrei";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
mysqli_select_db($conn,"Luminarias");
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} ?>
