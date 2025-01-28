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
    <h2>This is page !</h2>
    <br>
    <a href="learn3.php">Go to home </a>
    <br>
</body>
</html>

<?php

$_SESSION["username"] = $_POST["username"];
$_SESSION["password"] = $_POST["password"] ;

?>