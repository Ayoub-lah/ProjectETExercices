<?php

abstract class Compte{
    protected $_Code ;
    protected $_Solde ; 

    public function __construct( $C , $S) {
        $this->$_Code = $C;
        $this->$_Solde = $S;
    }
    public function verser($mt){
        $this->$_Solde +=$mt;
    }
    public function getCode(){
        return $this->$_Code ;
    }
    public function retirer($mt){
        $this->$_Solde -=$mt;
    }
    public function getCompteState(){
        foreach($this as $key=>$value)
            echo ($key ."=" .$value . "<br>");
    }
}

class CompteCourant extends Compte{
    private $_decouvert ;

    public function __construct($C , $S , $dec){
        parent::__construct($C ,$S);
        $this->$_decouvert = $dec ;
    }
    public function retirer($mt){
        parent::retirer($mt);
    }
    public function getCompteState(){
        parent::getCompteState();
    }

}

interface IBanque{
    public function addCompte(Compte $c);
    public function afficherComptes();
}

interface IAdmin{
    public function supprimerCompte($_Code);
}

class Banque implements IBanque , IAdmin{
    private $compte=array();

    public function addCompte(Compte $cp){
        $index = count($this->compte);
        $this->$compte[$index]=$cp ;
    }

    public function afficherComptes(){
        $index = count($this->$compte);
        foreach($this->$compte as $cp ){
            $cp->getCompteState();
            echo "<br>" ;
        }
    }

    public function supprimerCompte($code){
        $index = count($this->$compte);
        for($i=0 ; $i<$index ; $i++){
            if($this->$compte[$i]->getCode()==$code){
                unset($this->$compte[$i]) ;
                break ;
            }
        }
    }
}













?>