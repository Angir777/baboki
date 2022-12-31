-- phpMyAdmin SQL Dump
-- version 4.9.5
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Czas generowania: 31 Gru 2022, 12:56
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

--
-- Zrzut danych tabeli `mycms_blog_tags_dict`
--

INSERT INTO `mycms_blog_tags_dict` (`id_tag`, `name`, `position`, `hidden`) VALUES
(1, 'baboki', 1, 0),
(2, 'handmade', 2, 0);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_discount`
--

CREATE TABLE `mycms_discount` (
  `id_discount` int(11) NOT NULL,
  `code` longtext NOT NULL,
  `active` int(11) NOT NULL COMMENT '0 - Aktywny | 1 - Wykorzystany'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Zrzut danych tabeli `mycms_discount`
--

INSERT INTO `mycms_discount` (`id_discount`, `code`, `active`) VALUES
(1, 'BABOKFB190111', 0),
(2, 'BABOKFB200211', 0);

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

--
-- Zrzut danych tabeli `mycms_language`
--

INSERT INTO `mycms_language` (`id_language`, `name`, `shortcut`, `hidden`) VALUES
(1, 'Polski', 'pl', 0),
(2, 'English', 'en', 0);

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

--
-- Zrzut danych tabeli `mycms_products`
--

INSERT INTO `mycms_products` (`id_product`, `name_product`, `ref_product`, `price`, `quantity`, `delivery_time`, `promo_product`, `description_product_pl`, `description_product_en`, `technical_informations_pl`, `technical_informations_en`, `hidden`) VALUES
(1, 'Własny projekt', '001', 70, 0, 10, 0, '', '', '', '', 1),
(2, 'Renifer Zygmunt', '002', 55, 3, 7, 0, 'Zygmunt to nie byle jaki Babok. To Babok renifer! Ma wspaniałe poroże i wielki czerwony nochal. W święta pracuje na pełen etat dla Świętego Mikołaja, a w wolnym czasie lubi hasać po lesie :D', 'Zygmunt is not just any Babok. It\'s Babok reindeer! He has great antlers and a big red nose. During the holidays, he works full-time for Santa Claus, and in his free time he likes to romp around in the woods :D', '', '', 0),
(3, 'Zombie', '003', 55, 2, 7, 0, 'Zombie jest fantastycznym Babokiem, którego można tulić nie tylko w Halloween! Ma bardzo śmieszny wyraz twarzy i super milusie futerko!', 'Zombie is a fantastic Babok that can be cuddled not only on Halloween! She has a very funny expression on her face and super cute fur!', '', '', 0),
(4, 'Wiedźminek', '004', 60, 3, 7, 0, 'Wiedźminek podobnie jak Babok Indianin jest dumnym baboczyskiem. Ma groźną minę, która przestraszy nie jednego potworka spod łóżka. Dodatkowo na swoich plecach nosi specjalny miecz. Wygląda groźnie, ale bez obaw, jest tak samo przytulny jak wszystkie inne nasze maskotki.', 'Wiedźminek similarly to Babok Indianin is a brave babok. His dangerous face can aware monsters hiding under your bed. His carring on his back a sword.', '', '', 0),
(5, 'Lisacz', '005', 55, 3, 7, 0, 'Oto prawdziwy rudzielec w Babokowej rodzinie. Lisacz jest małym, radosnym liskiem. Podobno ma korzenie japońskie ze względu na swoje oczy no ale na razie nie zostało to potwierdzone.', 'Here is a real redhead in Babok\'s family. The fox is a small, happy fox. It is rumored that he has Japanese roots due to his eyes, but this has not been confirmed yet.', '', '', 0),
(6, 'Indianin', '006', 55, 2, 7, 0, 'Ten dumny koleś z dalekich dzikich krajów to Babok Indianin, ale nie musisz się go bać. Jest tak samo przytulny jak wszystkie inne Baboki. Mamy do niego bardzo duży szacunek i sentyment, ponieważ był on pierwszym Babokiem na świecie!', 'This proud dude from distant wild lands is Babok Indian, but you don\'t have to be afraid of him. He is just as cozy as all other Baboks. We have a lot of respect and sentiment for him, because he was the first Babok in the world!', '', '', 0),
(7, 'Wąsacz', '007', 55, 3, 7, 0, 'Ten stylowy i elegancki dżentelmen to Babok Wąsacz. Posiada on niebywałych rozmiarów wąsy, o które bardzo dba! Uwielbia przesiadywać w kawiarniach lub bibliotekach, gdzie swoją drogą fantastycznie prezentuje się na różnego rodzaju kanapach, fotelach i półkach.', 'This stylish and elegant gentleman is Babok Wąsacz. He has an incredible mustache, which he cares about very much! He loves hanging out in cafes or libraries, where, by the way, he looks fantastic on various types of sofas, armchairs and shelves.', '', '', 0),
(8, 'Pułkownik', '008', 55, 3, 7, 0, 'A co to za czerwone baboczysko z wielkim wąsem?! To Babok Pułkownik! \r\nLubi jak wszystko jest tak jak on chce! A jak nie jest… To strzela… focha! O!', 'And what is this red baboczysko with a big mustache?! It\'s Babok Colonel! He likes everything to be the way he wants it! And if it\'s not ... It shoots ... sulk! ABOUT!', '', '', 0),
(9, 'Panda', '009', 55, 3, 7, 0, 'Panda przybyła do nas z dalekiej Azji. Jest mega słodka i milusia. W sam raz do przytulania, miziania, ściskania i oczywiście zabawy :) Fantastycznie prezentuje się też na kanapach, fotelach i półkach :)', 'Panda came to us from distant Asia. She is super sweet and cuddly. Perfect for cuddling, cuddling, squeezing and of course having fun :) It also looks fantastic on sofas, armchairs and shelves :)', '', '', 0),
(10, 'Babpool Mały', '010', 35, -4, 7, 0, 'Przed Wami superbohater w wersji kieszonkowej! Babpool Mały jest uśmiechnięty i nosi na plecach dwa superaśne miecze! Można go wziąć ze sobą w każde miejsce i wszędzie się zmieści :D', 'Here\'s a superhero in a pocket version! Babpool Small is smiling and carrying two awesome swords on his back! You can take it with you anywhere and it fits everywhere :D', '', '', 0),
(11, 'Babpool', '011', 60, -3, 7, 0, 'Przed Wami prawdziwy superbohater! Babpool jest uśmiechnięty i nosi na plecach dwa superaśne miecze! Można je wyjąć i stanąć ramie w ramie z Babpoolem walcząc ze złem!', 'We present you a real hero! Babpool is smiling a lot! His wearing two amazing swords! You can take them off and fight along with this amazing Babpool.', '', '', 0),
(12, 'Kapitan Babok', '012', 60, 2, 7, 0, 'Kapitan Babok jest odważny i nieugięty! Nosi na plecach swoją niezwykłą tarczę :) Możesz ją zdjąć i pomóc kapitanowi przywrócić porządek i spokój w swoim pokoju!', 'Kapitan Babok is a really brave guy! He\'s carring his amazing shield :) You can take this off and help him to restore the peace at your own room!', '', '', 0),
(13, 'Kicaj', '013', 55, -1, 7, 0, 'Przedstawiamy kolejnego babokowego zwierzaka! Kicaj nie jest byle jakim zającem, to Babok o wielkim sercu. Gotowy jest pójść w ogień za swoimi przyjaciółmi! Albo spuścić łomot swoim wrogom :P', 'Introducing another animal! not just any rabbit, it\'s a big-hearted Babok. He\'s very friendly.', '', '', 0);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_products_category`
--

CREATE TABLE `mycms_products_category` (
  `id` int(11) NOT NULL,
  `id_product` int(11) NOT NULL,
  `id_category` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Zrzut danych tabeli `mycms_products_category`
--

INSERT INTO `mycms_products_category` (`id`, `id_product`, `id_category`) VALUES
(1, 1, 1),
(2, 4, 1),
(3, 10, 1),
(4, 11, 1),
(5, 12, 1),
(6, 10, 3),
(7, 2, 2),
(8, 5, 2),
(9, 3, 1),
(10, 6, 1),
(11, 8, 1),
(12, 13, 2);

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

--
-- Zrzut danych tabeli `mycms_products_category_dict`
--

INSERT INTO `mycms_products_category_dict` (`id_category`, `name_pl`, `url_pl`, `name_en`, `url_en`, `position`, `hidden`) VALUES
(1, 'Bohaterowie', 'bohaterowie', 'Heroes', 'heroes', 1, 0),
(2, 'Zwierzątka', 'zwierzatka', 'Animals', 'animals', 2, 0);

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

--
-- Zrzut danych tabeli `mycms_products_orders`
--

INSERT INTO `mycms_products_orders` (`id_order`, `order_number`, `delivery_method`, `delivery_price`, `payment_method`, `comment`, `create_toy`, `info_buyer`, `email_buyer`, `info_product`, `product_price`, `discount`, `final_price`, `status`, `hidden`) VALUES
(1, '2019/11/02/3', 3, '14.99', 2, 'Testowe zamówienie.', 'b_color_7,b_eyes_4,b_mimicry_7,b_ears_9,b_face_5,b_nose_25,b_handle_5,b_accessories_1|b_accessories_2|b_accessories_3|b_accessories_4|b_accessories_5|b_accessories_6|b_accessories_7|b_accessories_8|b_accessories_9|b_accessories_10|b_accessories_11|b_accessories_12|b_accessories_13|b_accessories_14|b_accessories_15|b_accessories_16|b_accessories_17|b_accessories_18|b_accessories_19|b_accessories_20|b_accessories_21|b_accessories_22|b_accessories_23|b_accessories_24|b_accessories_25|b_accessories_26|b_accessories_27|b_accessories_28|b_accessories_29|.', 'Testowe zamówienie.', 'mail@example.pl', 'Własny projekt,001,70,1/', '70.00', 0, '84.99', 3, 0);

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

--
-- Zrzut danych tabeli `mycms_products_photo`
--

INSERT INTO `mycms_products_photo` (`id_product_photo`, `product_id`, `name`, `description_pl`, `description_en`, `position`, `hidden`) VALUES
(1, 1, '1_1.jpg', 'Własny pluszak', 'Own mascot', 1, 0),
(2, 2, '2_2.jpg', '', '', 1, 0),
(3, 2, '3_2.jpg', '', '', 2, 0),
(4, 2, '4_2.jpg', '', '', 3, 0),
(5, 3, '5_3.jpg', '', '', 1, 0),
(6, 3, '6_3.jpg', '', '', 2, 0),
(7, 3, '7_3.jpg', '', '', 3, 0),
(8, 4, '8_4.jpg', '', '', 1, 0),
(9, 4, '9_4.jpg', '', '', 2, 0),
(10, 4, '10_4.jpg', '', '', 3, 0),
(11, 5, '11_5.jpg', '', '', 1, 0),
(12, 5, '12_5.jpg', '', '', 2, 0),
(13, 5, '13_5.jpg', '', '', 3, 0),
(15, 6, '15_6.jpg', '', '', 1, 0),
(16, 6, '16_6.jpg', '', '', 2, 0),
(17, 6, '17_6.jpg', '', '', 3, 0),
(18, 7, '18_7.jpg', '', '', 1, 0),
(19, 7, '19_7.jpg', '', '', 2, 0),
(20, 7, '20_7.jpg', '', '', 3, 0),
(21, 8, '21_8.jpg', '', '', 1, 0),
(22, 8, '22_8.jpg', '', '', 2, 0),
(23, 8, '23_8.jpg', '', '', 3, 0),
(24, 9, '24_9.jpg', '', '', 1, 0),
(25, 9, '25_9.jpg', '', '', 2, 0),
(26, 9, '26_9.jpg', '', '', 3, 0),
(27, 10, '27_10.jpg', '', '', 1, 0),
(28, 10, '28_10.jpg', '', '', 2, 0),
(29, 10, '29_10.jpg', '', '', 3, 0),
(30, 11, '30_11.jpg', '', '', 1, 0),
(31, 11, '31_11.jpg', '', '', 2, 0),
(32, 11, '32_11.jpg', '', '', 3, 0),
(33, 12, '33_12.jpg', '', '', 1, 0),
(34, 12, '34_12.jpg', '', '', 2, 0),
(35, 12, '35_12.jpg', '', '', 3, 0),
(36, 13, '36_13.jpg', '', '', 1, 0),
(37, 13, '37_13.jpg', '', '', 2, 0);

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

--
-- Zrzut danych tabeli `mycms_slider`
--

INSERT INTO `mycms_slider` (`id_slider`, `file_name_pl`, `file_name_en`, `url_pl`, `url_en`, `position`, `hidden`) VALUES
(1, '1_slider_pl.jpg', '1_slider_en.jpg', '', '', 1, 0),
(2, '2_slider_pl.jpg', '2_slider_en.jpg', '', '', 2, 0),
(3, '3_slider_pl.jpg', '3_slider_en.jpg', '', '', 3, 0),
(4, 'none.jpg', 'none.jpg', '', '', 4, 1);

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

--
-- Zrzut danych tabeli `mycms_users`
--

INSERT INTO `mycms_users` (`id_user`, `user_login`, `user_password`, `signature`, `user_permissions`) VALUES
(1, 'admin', '$2y$12$Nnp0cUNaFZBEYZvd.6YyDOiLrAXSY9OIjdn/bH6O.mPlhp6zKqVZW', 'Admin', 2);

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

--
-- Zrzut danych tabeli `mycms_users_menu`
--

INSERT INTO `mycms_users_menu` (`id_menu`, `name`, `link`, `position`, `hidden`) VALUES
(1, 'Strony', 'pages', 1, 0),
(2, 'Aktualności', 'news', 2, 0),
(3, 'Slider', 'slider', 3, 0),
(4, 'Galeria', 'gallery', 4, 0),
(5, 'Pliki', 'files', 5, 0),
(6, 'Shop', 'shop', 6, 0),
(7, 'Newsletter', 'newsletter', 7, 0),
(8, 'Ustawienia', 'settings', 8, 0);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `mycms_users_menu_permissions`
--

CREATE TABLE `mycms_users_menu_permissions` (
  `menu_id` int(11) NOT NULL,
  `user_permissions` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Zrzut danych tabeli `mycms_users_menu_permissions`
--

INSERT INTO `mycms_users_menu_permissions` (`menu_id`, `user_permissions`) VALUES
(2, 1),
(2, 2),
(3, 1),
(3, 2),
(6, 1),
(6, 2),
(7, 1),
(7, 2),
(8, 1),
(8, 2);

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
  MODIFY `id_tag` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT dla tabeli `mycms_discount`
--
ALTER TABLE `mycms_discount`
  MODIFY `id_discount` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT dla tabeli `mycms_language`
--
ALTER TABLE `mycms_language`
  MODIFY `id_language` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT dla tabeli `mycms_products`
--
ALTER TABLE `mycms_products`
  MODIFY `id_product` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT dla tabeli `mycms_products_category`
--
ALTER TABLE `mycms_products_category`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT dla tabeli `mycms_products_category_dict`
--
ALTER TABLE `mycms_products_category_dict`
  MODIFY `id_category` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT dla tabeli `mycms_products_orders`
--
ALTER TABLE `mycms_products_orders`
  MODIFY `id_order` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT dla tabeli `mycms_products_photo`
--
ALTER TABLE `mycms_products_photo`
  MODIFY `id_product_photo` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=38;

--
-- AUTO_INCREMENT dla tabeli `mycms_slider`
--
ALTER TABLE `mycms_slider`
  MODIFY `id_slider` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT dla tabeli `mycms_users`
--
ALTER TABLE `mycms_users`
  MODIFY `id_user` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT dla tabeli `mycms_users_menu`
--
ALTER TABLE `mycms_users_menu`
  MODIFY `id_menu` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
