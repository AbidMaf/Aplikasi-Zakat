-- phpMyAdmin SQL Dump
-- version 5.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 22, 2020 at 04:59 PM
-- Server version: 10.4.11-MariaDB
-- PHP Version: 7.4.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `cpp_db`
--

-- --------------------------------------------------------

--
-- Table structure for table `fitrah`
--

CREATE TABLE `fitrah` (
  `id` int(11) NOT NULL,
  `nama` varchar(255) NOT NULL,
  `rt` int(11) NOT NULL,
  `jml_jiwa` int(11) NOT NULL,
  `jenis` enum('uang','beras') NOT NULL,
  `sedekah` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `fitrah`
--

INSERT INTO `fitrah` (`id`, `nama`, `rt`, `jml_jiwa`, `jenis`, `sedekah`) VALUES
(2, 'Abid Mafahim', 3, 5, 'uang', 10000),
(3, 'Naf', 5, 4, 'uang', 10000),
(4, 'Mahatma Gandhi', 2, 5, 'beras', 3),
(7, 'Afsfs', 5, 3, 'uang', 25000),
(8, 'fsdg', 4, 3, 'uang', 125000);

-- --------------------------------------------------------

--
-- Table structure for table `mal`
--

CREATE TABLE `mal` (
  `id` int(11) NOT NULL,
  `nama` varchar(255) NOT NULL,
  `penghasilan` float NOT NULL,
  `sedekah` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `mal`
--

INSERT INTO `mal` (`id`, `nama`, `penghasilan`, `sedekah`) VALUES
(1, 'Abid Mafahim', 5000000, 75000),
(2, 'Nafisah Hasya Nadana', 6000000, 50000),
(6, 'fsd ', 3000000, 0),
(7, 'Asdf', 5000000, 75000);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `fitrah`
--
ALTER TABLE `fitrah`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `mal`
--
ALTER TABLE `mal`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `fitrah`
--
ALTER TABLE `fitrah`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `mal`
--
ALTER TABLE `mal`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
