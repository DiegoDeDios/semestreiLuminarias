<?php
//echo '<script src="https://code.jquery.com/jquery-2.1.4.min.js"></script>';
include 'dbc.php';

$ACK = "OK";
$FAIL = "ERROR";
$idStatus=$_GET['idStatus'];
$MAC=$_GET['MAC'];
$IP=$_GET['IP'];
$Voltaje=$_GET['Voltaje'];
$Estado=$_GET['Estado'];
$stDate=$_GET['stDate'];

$query="INSERT INTO lampStatus VALUES ($idStatus,'$MAC','$IP', $Voltaje,'$Estado',$stDate)";
if ($conn->query($query) === TRUE) {

    $querySelect = "SELECT * FROM lampRef WHERE MAC ='$MAC'";
    $result = $conn->query($querySelect);
    while($row = $result->fetch_assoc()) {
          echo "Voltaje%?" . $row["refVolt"]. ".  ActTime%?" .$row["actTime"].". <br>";
      }
  }
 else {
    echo "<br></br>".$FAIL."<br></br>";
    echo mysqli_error($conn);
}

?>
