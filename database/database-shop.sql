-- phpMyAdmin SQL Dump
-- version 4.9.5
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Czas generowania: 31 Gru 2022, 11:36
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
-- Baza danych: `serwer16603_b1`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_blog`
--

CREATE TABLE `mycms_blog` (
  `id_news` int(11) NOT NULL,
  `title` varchar(255) NOT NULL,
  `lead` text NOT NULL,
  `contents` text DEFAULT NULL,
  `date_news` varchar(10) NOT NULL,
  `blog_description` varchar(255) NOT NULL,
  `blog_keywords` varchar(255) NOT NULL,
  `author` varchar(11) NOT NULL,
  `hidden` tinyint(1) NOT NULL DEFAULT 0 COMMENT '0 - widoczny | 1 - ukryty'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_blog_file`
--

CREATE TABLE `mycms_blog_file` (
  `id_news_file` int(11) NOT NULL,
  `news_id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `description` varchar(255) NOT NULL,
  `position` tinyint(1) NOT NULL DEFAULT 0,
  `hidden` tinyint(1) NOT NULL DEFAULT 0 COMMENT '0 - widoczny | 1 - ukryty'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_blog_photo`
--

CREATE TABLE `mycms_blog_photo` (
  `id_news_photo` int(11) NOT NULL,
  `news_id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `description` varchar(255) NOT NULL,
  `position` tinyint(1) NOT NULL DEFAULT 0,
  `hidden` tinyint(1) NOT NULL DEFAULT 0 COMMENT '0 - widoczny | 1 - ukryty'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_blog_tags`
--

CREATE TABLE `mycms_blog_tags` (
  `id` int(11) NOT NULL,
  `id_blog` int(11) NOT NULL,
  `id_tag` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_blog_tags_dict`
--

CREATE TABLE `mycms_blog_tags_dict` (
  `id_tag` int(11) NOT NULL,
  `name` varchar(50) NOT NULL,
  `position` tinyint(1) NOT NULL,
  `hidden` tinyint(1) NOT NULL COMMENT '0 - widoczny | 1 - ukryty'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_discount`
--

CREATE TABLE `mycms_discount` (
  `id_discount` int(11) NOT NULL,
  `code` longtext NOT NULL,
  `active` int(11) NOT NULL COMMENT '0 - Aktywny | 1 - Wykorzystany'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_language`
--

CREATE TABLE `mycms_language` (
  `id_language` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `shortcut` varchar(255) NOT NULL,
  `hidden` tinyint(4) NOT NULL DEFAULT 0 COMMENT '0 - widoczny | 1 - ukryty'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_products`
--

CREATE TABLE `mycms_products` (
  `id_product` int(11) NOT NULL,
  `name_product` varchar(255) NOT NULL,
  `ref_product` varchar(50) DEFAULT NULL,
  `price` int(11) DEFAULT NULL,
  `quantity` int(11) DEFAULT NULL,
  `delivery_time` int(10) NOT NULL DEFAULT 7,
  `promo_product` int(255) DEFAULT 0,
  `description_product_pl` longtext DEFAULT NULL,
  `description_product_en` longtext NOT NULL,
  `technical_informations_pl` longtext DEFAULT NULL,
  `technical_informations_en` longtext NOT NULL,
  `hidden` tinyint(1) NOT NULL DEFAULT 0 COMMENT '0 - widoczny | 1 - ukryty'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_products_category`
--

CREATE TABLE `mycms_products_category` (
  `id` int(11) NOT NULL,
  `id_product` int(11) NOT NULL,
  `id_category` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_products_category_dict`
--

CREATE TABLE `mycms_products_category_dict` (
  `id_category` int(11) NOT NULL,
  `name_pl` varchar(50) NOT NULL,
  `url_pl` varchar(50) NOT NULL,
  `name_en` varchar(50) NOT NULL,
  `url_en` varchar(50) NOT NULL,
  `position` tinyint(1) NOT NULL,
  `hidden` tinyint(1) NOT NULL COMMENT '0 - widoczny | 1 - ukryty'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_products_orders`
--

CREATE TABLE `mycms_products_orders` (
  `id_order` int(11) NOT NULL,
  `order_number` varchar(255) NOT NULL,
  `delivery_method` tinyint(1) NOT NULL COMMENT '1 - Odbiór osobisty | 2 - DPD | 3 - PocztaPolska(Kraj) | 4 - PocztaPolska(Eksport)',
  `delivery_price` decimal(10,2) NOT NULL,
  `payment_method` tinyint(1) NOT NULL DEFAULT 2 COMMENT '1 - Zapłata na miejscu | 2 - Przelew tradycyjny | 3 - Przelewy24',
  `comment` longtext NOT NULL,
  `create_toy` longtext NOT NULL,
  `info_buyer` longtext NOT NULL,
  `email_buyer` varchar(255) NOT NULL,
  `info_product` varchar(255) NOT NULL,
  `product_price` decimal(10,2) NOT NULL,
  `discount` int(11) NOT NULL DEFAULT 0 COMMENT 'Dane w %',
  `final_price` decimal(10,2) NOT NULL,
  `status` tinyint(1) NOT NULL DEFAULT 0 COMMENT '0 - do opłacenia | 1 -w trakcie | 2 - wysłane | 3 - zakończone | 4 - anulowane',
  `hidden` tinyint(1) NOT NULL DEFAULT 0 COMMENT '0 - widoczny | 1 - ukryty'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_products_photo`
--

CREATE TABLE `mycms_products_photo` (
  `id_product_photo` int(11) NOT NULL,
  `product_id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `description_pl` varchar(255) NOT NULL,
  `description_en` varchar(255) NOT NULL,
  `position` tinyint(1) NOT NULL DEFAULT 0,
  `hidden` tinyint(1) NOT NULL DEFAULT 0 COMMENT '0 - widoczny | 1 - ukryty'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_slider`
--

CREATE TABLE `mycms_slider` (
  `id_slider` int(11) NOT NULL,
  `file_name_pl` varchar(255) DEFAULT 'none.jpg',
  `file_name_en` varchar(255) NOT NULL DEFAULT 'none.jpg',
  `url_pl` varchar(255) DEFAULT NULL,
  `url_en` varchar(255) DEFAULT NULL,
  `position` tinyint(1) NOT NULL DEFAULT 0,
  `hidden` tinyint(1) NOT NULL DEFAULT 1 COMMENT '0 - widoczny | 1 - ukryty'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_users`
--

CREATE TABLE `mycms_users` (
  `id_user` int(11) NOT NULL,
  `user_login` varchar(30) NOT NULL,
  `user_password` varchar(60) NOT NULL,
  `signature` varchar(50) NOT NULL,
  `user_permissions` int(11) NOT NULL DEFAULT 0 COMMENT '2 - head admin | 1 - admin | 0 - user'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_users_menu`
--

CREATE TABLE `mycms_users_menu` (
  `id_menu` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `link` varchar(255) NOT NULL,
  `position` tinyint(1) NOT NULL DEFAULT 0,
  `hidden` tinyint(1) NOT NULL DEFAULT 0 COMMENT '0 - widoczny | 1 - ukryty'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_users_menu_permissions`
--

CREATE TABLE `mycms_users_menu_permissions` (
  `menu_id` int(11) NOT NULL,
  `user_permissions` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `mycms_blog`
--
ALTER TABLE `mycms_blog`
  ADD PRIMARY KEY (`id_news`);

--
-- Indeksy dla tabeli `mycms_blog_file`
--
ALTER TABLE `mycms_blog_file`
  ADD PRIMARY KEY (`id_news_file`);

--
-- Indeksy dla tabeli `mycms_blog_photo`
--
ALTER TABLE `mycms_blog_photo`
  ADD PRIMARY KEY (`id_news_photo`);

--
-- Indeksy dla tabeli `mycms_blog_tags`
--
ALTER TABLE `mycms_blog_tags`
  ADD PRIMARY KEY (`id`);

--
-- Indeksy dla tabeli `mycms_blog_tags_dict`
--
ALTER TABLE `mycms_blog_tags_dict`
  ADD PRIMARY KEY (`id_tag`);

--
-- Indeksy dla tabeli `mycms_discount`
--
ALTER TABLE `mycms_discount`
  ADD PRIMARY KEY (`id_discount`);

--
-- Indeksy dla tabeli `mycms_language`
--
ALTER TABLE `mycms_language`
  ADD PRIMARY KEY (`id_language`);

--
-- Indeksy dla tabeli `mycms_products`
--
ALTER TABLE `mycms_products`
  ADD PRIMARY KEY (`id_product`);

--
-- Indeksy dla tabeli `mycms_products_category`
--
ALTER TABLE `mycms_products_category`
  ADD PRIMARY KEY (`id`);

--
-- Indeksy dla tabeli `mycms_products_category_dict`
--
ALTER TABLE `mycms_products_category_dict`
  ADD PRIMARY KEY (`id_category`);

--
-- Indeksy dla tabeli `mycms_products_orders`
--
ALTER TABLE `mycms_products_orders`
  ADD PRIMARY KEY (`id_order`,`order_number`);

--
-- Indeksy dla tabeli `mycms_products_photo`
--
ALTER TABLE `mycms_products_photo`
  ADD PRIMARY KEY (`id_product_photo`);

--
-- Indeksy dla tabeli `mycms_slider`
--
ALTER TABLE `mycms_slider`
  ADD PRIMARY KEY (`id_slider`);

--
-- Indeksy dla tabeli `mycms_users`
--
ALTER TABLE `mycms_users`
  ADD PRIMARY KEY (`id_user`);

--
-- Indeksy dla tabeli `mycms_users_menu`
--
ALTER TABLE `mycms_users_menu`
  ADD PRIMARY KEY (`id_menu`);

--
-- Indeksy dla tabeli `mycms_users_menu_permissions`
--
ALTER TABLE `mycms_users_menu_permissions`
  ADD KEY `dzial_id` (`menu_id`);

--
-- AUTO_INCREMENT dla tabel zrzutów
--

--
-- AUTO_INCREMENT dla tabeli `mycms_blog`
--
ALTER TABLE `mycms_blog`
  MODIFY `id_news` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT dla tabeli `mycms_blog_file`
--
ALTER TABLE `mycms_blog_file`
  MODIFY `id_news_file` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT dla tabeli `mycms_blog_photo`
--
ALTER TABLE `mycms_blog_photo`
  MODIFY `id_news_photo` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT dla tabeli `mycms_blog_tags`
--
ALTER TABLE `mycms_blog_tags`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT dla tabeli `mycms_blog_tags_dict`
--
ALTER TABLE `mycms_blog_tags_dict`
  MODIFY `id_tag` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT dla tabeli `mycms_discount`
--
ALTER TABLE `mycms_discount`
  MODIFY `id_discount` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT dla tabeli `mycms_language`
--
ALTER TABLE `mycms_language`
  MODIFY `id_language` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT dla tabeli `mycms_products`
--
ALTER TABLE `mycms_products`
  MODIFY `id_product` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT dla tabeli `mycms_products_category`
--
ALTER TABLE `mycms_products_category`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT dla tabeli `mycms_products_category_dict`
--
ALTER TABLE `mycms_products_category_dict`
  MODIFY `id_category` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT dla tabeli `mycms_products_orders`
--
ALTER TABLE `mycms_products_orders`
  MODIFY `id_order` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT dla tabeli `mycms_products_photo`
--
ALTER TABLE `mycms_products_photo`
  MODIFY `id_product_photo` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT dla tabeli `mycms_slider`
--
ALTER TABLE `mycms_slider`
  MODIFY `id_slider` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT dla tabeli `mycms_users`
--
ALTER TABLE `mycms_users`
  MODIFY `id_user` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT dla tabeli `mycms_users_menu`
--
ALTER TABLE `mycms_users_menu`
  MODIFY `id_menu` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
