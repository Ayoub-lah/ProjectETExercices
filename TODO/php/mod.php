<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="css/bootstrap.min.css">    
    <title>Document</title>
</head>
<body>

<?php

if(!isset($_POST['id'])){
    header('Location: index.php') ;
}
    
require_once 'include/DB.php' ;
include_once 'include/nav.php' ;

$id = $_POST['id'] ;

$sql = $conn->prepare('SELECT * FROM items WHERE id = ?');
$sql->execute([$id]);
$item = $sql->fetch(PDO::FETCH_OBJ);

?>

<div class="container">
<div class="border border-4 p-4 my-4" >

<?php
if (isset($_POST["modifier"])) {
        $title = $_POST['Title'];
        $id = $_POST['id'];
        if(!empty($id) && !empty($title)){
            $sql=$conn->prepare('UPDATE items SET label= ? WHERE ID= ?  ') ;
            $res=$sql->execute([$title  , $id]);
            if($res==true){
                header('Location: index.php') ;
            }
        }else{
            ?>
                <div class="alert alert-danger" role="alert">
                    The <span class="fw-bolder" >Title</span> is mandatory !
                </div>
            <?php
        }
}

?>
        <h3>Update your task : </h3>
        <form action="" method="POST">
            <input type="hidden" name="id" value="<?= $item->ID ?>">
            <label for="Title" class="form-label">Title *</label>
            <div class="input-group mb-3">
            <input type="text" class="form-control" id="Title" name="Title" placeholder="Update Task"  value="<?= htmlspecialchars($item->label) ?>">
            <input type="submit" class="btn btn-outline-success" name="modifier" value="Update">
            </div>
        </form>
    </div>
</div>

</body>
</html>