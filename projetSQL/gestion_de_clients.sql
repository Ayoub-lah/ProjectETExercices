-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: Dec 04, 2024 at 02:27 PM
-- Server version: 8.3.0
-- PHP Version: 8.2.18

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `gestion_de_clients`
--

-- --------------------------------------------------------

--
-- Table structure for table `article`
--

DROP TABLE IF EXISTS `article`;
CREATE TABLE IF NOT EXISTS `article` (
  `Idarticle` int NOT NULL,
  `Designation` varchar(25) DEFAULT NULL,
  `PrixUnitaire` decimal(10,2) DEFAULT NULL,
  `Qtstock` int DEFAULT NULL,
  PRIMARY KEY (`Idarticle`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `article`
--

INSERT INTO `article` (`Idarticle`, `Designation`, `PrixUnitaire`, `Qtstock`) VALUES
(200, 'Tapis', 100.00, 30),
(201, 'Lecteur Disk ', 1025.70, 2),
(202, 'Imprimante Matricielle ', 321.25, 15),
(203, 'Imprimante Lazer', 7000.00, 2),
(204, 'Souris', 700.00, 10),
(205, 'Disque Dur', 1200.00, 9),
(207, 'Imprimante Jet d\'encre', 5524.50, 6),
(208, 'Clavier', 3000.00, 27),
(209, 'Carte Video', 220.50, 3),
(210, 'Modem', 3420.50, 12),
(212, 'CD.ROM', 310.00, 10),
(213, 'Carte Mère ', 725.60, 7),
(214, 'Scanner', 12000.00, 4),
(217, 'Kit Multimédia', 325.00, 15),
(222, 'Mise à jour Office 2016 ', 3020.00, 5),
(301, 'Serveur HP ', 14720.00, 5),
(444, 'Ordinateur HP ', 15000.00, 2);

-- --------------------------------------------------------

--
-- Table structure for table `client`
--

DROP TABLE IF EXISTS `client`;
CREATE TABLE IF NOT EXISTS `client` (
  `Idclient` int NOT NULL,
  `Nom` varchar(25) DEFAULT NULL,
  `Adress` varchar(25) DEFAULT NULL,
  `Ville` varchar(25) DEFAULT NULL,
  `Telephone` varchar(25) DEFAULT NULL,
  PRIMARY KEY (`Idclient`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `client`
--

INSERT INTO `client` (`Idclient`, `Nom`, `Adress`, `Ville`, `Telephone`) VALUES
(21489, 'SAHEL', '6, Bd Hassany ', 'Rabat', '(0537) 95.25.14'),
(23156, 'MIKOU', '15, Bd 2 Mars', 'Casablanca ', '(0522) 94.22.36'),
(57423, 'ADAMI', '27, Bd Zerktouni', 'Casablanca', '(0522) 30.34.55'),
(80877, 'CHENAOUI', '28, Bd Md V ', 'Casablanca', '(0522) 43.02.57 '),
(105874, 'ALAOUI', '73, Avenue Lala Yacout', 'Casablanca', '(0522) 29.65.14 '),
(110175, 'BENYAHYA', '23, Rue La Fayette ', 'Casablanca', '(0522) 30.28.51 '),
(210279, 'CHAKIR', '354, Bd D\'Anfa', 'Casablanca', '(0522) 90.31.07 '),
(326598, 'BENMOUSSA', '13, Bd My Ismail ', 'Casablanca', '(0522) 32.12.55'),
(336941, 'BENAZOUZ', '13, Bd My Youssef ', 'Rabat', '(0537) 82.15.33 '),
(365722, 'OUMARI', '55, Rue Faidi Khalifa ', 'Marakkech', '(0524) 24.13.90 '),
(657251, 'RIAD', '84, Bd 11 janvier ', 'Rabat', '(0537) 30.38.55 '),
(698725, 'MANSOUR', '12, Avenue des FAR ', 'Fès', '(0535) 27.69.87 '),
(987265, '987265', '99, Rue Colbert ', 'Oujda', '(0536) 61.25.33 '),
(987542, 'BORJA', '62, Hay El Hana ', 'Fès', '(0535) 80.37.08 '),
(998750, 'FARABI', '53, Maarif ', 'Kénitra', '(0537) 98.25.47 ');

-- --------------------------------------------------------

--
-- Table structure for table `clients_casa`
--

DROP TABLE IF EXISTS `clients_casa`;
CREATE TABLE IF NOT EXISTS `clients_casa` (
  `Idclient` int NOT NULL,
  `Nom` varchar(25) DEFAULT NULL,
  `Adress` varchar(25) DEFAULT NULL,
  `Ville` varchar(25) DEFAULT NULL,
  `Telephone` varchar(25) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `clients_casa`
--

INSERT INTO `clients_casa` (`Idclient`, `Nom`, `Adress`, `Ville`, `Telephone`) VALUES
(57423, 'ADAMI', '27, Bd Zerktouni', 'Casablanca', '(0522) 30.34.55'),
(80877, 'CHENAOUI', '28, Bd Md V ', 'Casablanca', '(0522) 43.02.57 '),
(105874, 'ALAOUI', '73, Avenue Lala Yacout', 'Casablanca', '(0522) 29.65.14 '),
(110175, 'BENYAHYA', '23, Rue La Fayette ', 'Casablanca', '(0522) 30.28.51 '),
(210279, 'CHAKIR', '354, Bd D\'Anfa', 'Casablanca', '(0522) 90.31.07 '),
(326598, 'BENMOUSSA', '13, Bd My Ismail ', 'Casablanca', '(0522) 32.12.55');

-- --------------------------------------------------------

--
-- Table structure for table `commande`
--

DROP TABLE IF EXISTS `commande`;
CREATE TABLE IF NOT EXISTS `commande` (
  `Numcom` int NOT NULL,
  `Idclient` int NOT NULL,
  `Datecom` date DEFAULT NULL,
  PRIMARY KEY (`Numcom`),
  KEY `fk_Idclient` (`Idclient`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `commande`
--

INSERT INTO `commande` (`Numcom`, `Idclient`, `Datecom`) VALUES
(971, 110175, '2019-01-28'),
(937, 21489, '2018-08-13'),
(854, 210279, '2018-05-15'),
(789, 336941, '2018-01-07'),
(349, 80877, '2017-09-23'),
(208, 105874, '2017-08-02'),
(159, 105874, '2016-11-10'),
(125, 110175, '2015-03-08');

-- --------------------------------------------------------

--
-- Table structure for table `ligne_commande`
--

DROP TABLE IF EXISTS `ligne_commande`;
CREATE TABLE IF NOT EXISTS `ligne_commande` (
  `Nuligne` int NOT NULL,
  `Numcom` int NOT NULL,
  `Idarticle` int NOT NULL,
  `Qtecom` int DEFAULT NULL,
  PRIMARY KEY (`Nuligne`),
  KEY `pk_Numcom` (`Numcom`),
  KEY `pk_Idarticle` (`Idarticle`),
  KEY `idx_Nuligne_Numcom` (`Nuligne`,`Numcom`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `ligne_commande`
--

INSERT INTO `ligne_commande` (`Nuligne`, `Numcom`, `Idarticle`, `Qtecom`) VALUES
(1, 159, 444, 9),
(2, 208, 217, 1),
(3, 349, 210, 14),
(4, 789, 222, 5),
(5, 937, 301, 7),
(6, 971, 214, 12);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
