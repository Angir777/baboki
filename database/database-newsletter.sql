-- phpMyAdmin SQL Dump
-- version 4.9.5
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Czas generowania: 31 Gru 2022, 11:38
-- Wersja serwera: 10.5.12-MariaDB-0+deb11u1
-- Wersja PHP: 7.4.28

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `serwer16603_b2`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_newsletter`
--

CREATE TABLE `mycms_newsletter` (
  `id_newsletter` int(11) NOT NULL,
  `email` varchar(255) NOT NULL,
  `lang` varchar(6) NOT NULL,
  `deleted` tinyint(1) NOT NULL DEFAULT 0 COMMENT '0 - nowy | 1 - stary',
  `date_addition` varchar(10) NOT NULL,
  `ip` longtext NOT NULL,
  `hidden` tinyint(4) NOT NULL DEFAULT 0 COMMENT '0 - widoczny | 1 - ukryty'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `mycms_newsletter`
--
ALTER TABLE `mycms_newsletter`
  ADD PRIMARY KEY (`id_newsletter`);

--
-- AUTO_INCREMENT dla tabel zrzutów
--

--
-- AUTO_INCREMENT dla tabeli `mycms_newsletter`
--
ALTER TABLE `mycms_newsletter`
  MODIFY `id_newsletter` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
