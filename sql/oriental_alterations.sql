
--22 April 2015--
ALTER TABLE `0_debtors_master`  ADD `tin_no` VARCHAR(50) NOT NULL AFTER `address`;
ALTER TABLE `0_debtors_master`  ADD `cst_no` VARCHAR(50) NULL AFTER `tin_no`

INSERT INTO `oriental`.`0_sys_prefs` (`name`, `category`, `type`, `length`, `value`) VALUES ('tin_no', 'setup.company', 'varchar', '50', NULL);

--
-- Table structure for table `0_trans_vehilces`
--
CREATE TABLE IF NOT EXISTS `0_trans_vehilces` (
  `trans_no` int(11) unsigned NOT NULL DEFAULT '0',
  `type` smallint(6) unsigned NOT NULL DEFAULT '0',
  `vehicle_no` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`trans_no`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
