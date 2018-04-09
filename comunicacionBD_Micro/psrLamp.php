<?php
//echo '<script src="https://code.jquery.com/jquery-2.1.4.min.js"></script>';
include 'dbc.php';

$ACK = "OK";
$FAIL = "ERROR";
$idLamp=$_GET['idLamp'];
$IP=$_GET['IP'];
$MAC=$_GET['MAC'];
$fechaAct=$_GET['fechaAct'];
$zonaUbic=$_GET['zonaUbic'];
$Status=$_GET['Status'];
$Volt=$_GET['Volt'];



$query="INSERT INTO Lampara VALUES ($idLamp,'$IP','$MAC', $fechaAct,'$zonaUbic','$Status','$Volt')";
if ($conn->query($query) === TRUE) {
    echo "<br></br>".$ACK."<br></br>";
} else {
    echo "<br></br>".$FAIL."<br></br>";
}

?>
