<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="learn.php" method="post">
        <label for="user">username :</label>
        <input type="text" name="username">
        <br>
        <label for="pass">password :</label>
        <input type="password" name="password">
        <br>
        <input type="submit" name="click" value="submit">
    </form>
</body>
</html>
<?php 
    
    require_once("include.php") ;

    if(isset($_POST["click"])){
        
        $username = $_POST["username"];
        $password = $_POST["password"];
        
        if(empty($username)){
            echo "username is missing ";
        }elseif(empty($password)){
            echo "password is missing " ;
        }else{
            echo "hello {$username}" ; 
        }
    }

    
?>