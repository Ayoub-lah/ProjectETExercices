<?php

    session_start();

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h2>This is login page !</h2>
    <br>
    <form action="learn3login.php" method="post">
        username :
        <input type="text" name="username" >
        <br>
        password : 
        <input type="password" name="password" >
        <br>
        <input type="button" name="click" value="login">
        <br>
    </form>
    <br>
</body>
</html>

<?php

if(isset($_POST["click"])){
    if(!empty($_POST["username"] ) && !empty($_POST["password"] )){

        $_SESSION["username"] = $_POST["username"];
        $_SESSION["password"] = $_POST["password"] ;
        
        header("location : learn3.php") ;
    }else{
        echo "missing username or password !!!!!!!" ;
    }
}

?>

