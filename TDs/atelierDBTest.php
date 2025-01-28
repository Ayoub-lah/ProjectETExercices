<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Test</title>
</head>
<body>
    
<form method="POST">
    <label for="ps">Pseudo :</label>
    <input type="text" name="ps" id="ps" >
    <br>
    <label for="Message">Message :</label>
    <input type="text" name="me" id="me">
    <br>
    <button>Envoyer</button>
</form>

<?php

$host = 'localhost';
$user = 'root' ; 
$pass = '' ; 
$DB  = 'test';

$conn =  mysqli_connect ($host , $user , $pass , $DB) or die(mysqli_connect_error());

$req = "SELECT pseudo, message FROM minichat";

$res = mysqli_query($conn , $req);

if(mysqli_num_rows($res)>0){

    echo '<table border="1">' ; 
    echo '<tr><th>ID</th><th>pseudo</th><th>message</th></tr>';

    while($row = mysqli_fetch_assoc($res)){
        echo '<tr>' ; 
        echo '<td>' .$row['ps'] . '</td>' ;
        echo '<td>' .$row['me'] . '</td>' ;
        echo '</tr>' ; 
    }
    echo '</table>' ;

}else echo 'pas de donne ';

mysqli_free_result($res);


?>






</body>
</html>