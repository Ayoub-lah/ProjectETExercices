<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="css/bootstrap.min.css">
    <title>TODO</title>

</head>
<body>
<?php require_once 'include/DB.php' ?>
<?php include_once 'include/nav.php' ?>
<div class="container">
    <div class="border border-4 p-4 my-4" >
        <?php
            $title='';
            if(isset($_POST['ajouter'])){
                $title = $_POST['Title'] ;
                if(!empty($title)){
                    $sql = $conn->prepare('insert into items values (null,?)');
                    $res=$sql->execute([$title]);
                    if($res==true){
                    ?>
                        <div class="alert alert-success" role="alert">
                            The Title submitted :<span class="fw-bolder" ><?=$title ?></span> 
                        </div>
                    <?php }
                }
                else {
                    ?> 
                    <div class="alert alert-danger" role="alert">
                        The <span class="fw-bolder" >Title</span> is mandatory !
                    </div>
                    <?php
                }
            }
        ?>
        <h3>What would you like to do : </h3>
        <form action="" method="POST" >
                <label for="Title" class="form-label">Title *</label>
                <div class="input-group mb-3">
                    <input type="text" class="form-control" id="Title" name="Title" placeholder="Add Tasks" aria-label="Recipient's username" aria-describedby="TitleHelp">
                    <button class="btn btn-outline-success" type="submit" id="button-addon2" name="ajouter">&#x2719;</button>
                </div>
        </form>
        <hr class="border border-black border-2 opacity-50">
        <h3>Your tasks :</h3>
        <?php 
            $req = "select * from items ";
            $res=$conn->query($req)->fetchAll(PDO::FETCH_OBJ);
        ?>
        <table class="table">
            <tbody class="table-group-divider">
                <?php 
                    foreach($res as $key => $val):
                        ?>
                            <tr>
                                <td scope="row">
                                    <div class="form-check form-check-inline">
                                        <input class="form-check-input" type="checkbox"  value="option2" name="check"  >
                                    </div>
                                </td>
                                <td><?= $val->label ?></td>
                                <td>
                                    <form method="POST">
                                        <div class="d-grid gap-2 d-md-flex justify-content-md-end">
                                            <input type="hidden" name="id" value=" <?= $val->ID ?> ">
                                            <input type="submit" class="btn btn-primary me-md-2" formaction="mod.php" name="update" value="&#x270E;">
                                            <input type="submit" class="btn btn-outline-danger" formaction="supp.php" name="delete" value="&#10007; ">    
                                        </div>
                                    </form>
                                </td>
                            </tr>
                        <?php
                    endforeach ;
                ?>
            </tbody>
        </table>
    </div>
</div>

</body>
</html>