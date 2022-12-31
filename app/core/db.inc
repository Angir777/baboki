<?php

    /**
    * This file is part of BABOKI.COM
    *
    * @author       Błażej Skrzypniak <hi@skrzypniak.pl>
    * @link         https://baboki.com
    */

    class db {

        protected function connect() {

            $host = '';
            $db   = '';
            $user = '';
            $pass = '';
            $charset = 'utf8mb4';

            $options = [
                \PDO::ATTR_ERRMODE            => \PDO::ERRMODE_EXCEPTION,
                \PDO::ATTR_DEFAULT_FETCH_MODE => \PDO::FETCH_ASSOC,
                \PDO::ATTR_EMULATE_PREPARES   => false,
            ];
            
            $dsn = "mysql:host=$host;dbname=$db;charset=$charset";

            try {
                $conn = new \PDO($dsn, $user, $pass, $options);
                $conn->exec("set names utf8");
                return $conn;
            } catch (\PDOException $e) {
                if ( DEV == true ) {
                    die("Couldn't connect!");
                }
            }
            
        } 

        protected function connectToNewsletter() {

            $host    = '';
            $db      = '';
            $user    = '';
            $pass    = '';
            $charset = '';

            $options = [
                \PDO::ATTR_ERRMODE            => \PDO::ERRMODE_EXCEPTION,
                \PDO::ATTR_DEFAULT_FETCH_MODE => \PDO::FETCH_ASSOC,
                \PDO::ATTR_EMULATE_PREPARES   => false,
            ];
            
            $dsn = "mysql:host=$host;dbname=$db;charset=$charset";
            
            try {
                $conn = new \PDO($dsn, $user, $pass, $options);
                $conn->exec("set names utf8");
                return $conn;
            } catch (\PDOException $e) {
                if ( DEV == true ) {
                    die("Couldn't connect!");
                }
            }
            
        }
      
    }