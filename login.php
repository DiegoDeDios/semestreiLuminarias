<?php
/* User login process, checks if user exists and password is correct */
// Escape email to protect against SQL injections
require 'dbc.php';
$email =$_POST['email'];
$query="SELECT * FROM Usuarios WHERE mailUsr='$email'";
$result = mysqli_query($conn, $query);
if ( $result->num_rows == 0 ){ // User doesn't exist
    header("location: index.php");
}
else { // User exists
    $user = $result->fetch_assoc();
    if (password_verify($_POST['password'], $user['password'])) {
        $_SESSION['email'] = $user['email'];
        $_SESSION['first_name'] = $user['first_name'];
        $_SESSION['last_name'] = $user['last_name'];
        $_SESSION['active'] = $user['active'];
        
        // This is how we'll know the user is logged in
        $_SESSION['logged_in'] = true;

        header("location: indexAdmin.php");
    }
    else {
        $_SESSION['message'] = "You have entered wrong password, try again!";
        header("location: index.php");
    }
}