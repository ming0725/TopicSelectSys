-- MySQL dump 10.13  Distrib 8.0.26, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: topic
-- ------------------------------------------------------
-- Server version	8.0.26

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Temporary view structure for view `account_adm`
--

DROP TABLE IF EXISTS `account_adm`;
/*!50001 DROP VIEW IF EXISTS `account_adm`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `account_adm` AS SELECT 
 1 AS `ad_id`,
 1 AS `password`*/;
SET character_set_client = @saved_cs_client;

--
-- Temporary view structure for view `account_stu`
--

DROP TABLE IF EXISTS `account_stu`;
/*!50001 DROP VIEW IF EXISTS `account_stu`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `account_stu` AS SELECT 
 1 AS `stu_id`,
 1 AS `password`*/;
SET character_set_client = @saved_cs_client;

--
-- Temporary view structure for view `account_tea`
--

DROP TABLE IF EXISTS `account_tea`;
/*!50001 DROP VIEW IF EXISTS `account_tea`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `account_tea` AS SELECT 
 1 AS `tea_id`,
 1 AS `password`*/;
SET character_set_client = @saved_cs_client;

--
-- Table structure for table `admin`
--

DROP TABLE IF EXISTS `admin`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `admin` (
  `ad_id` varchar(12) NOT NULL,
  `name` varchar(8) NOT NULL,
  `phone_number` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL DEFAULT '123456',
  PRIMARY KEY (`ad_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `admin`
--

LOCK TABLES `admin` WRITE;
/*!40000 ALTER TABLE `admin` DISABLE KEYS */;
INSERT INTO `admin` VALUES ('20210095','铭铭','00000000000','123456'),('admin','mingming','11111111111','123456');
/*!40000 ALTER TABLE `admin` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `check_admin` BEFORE INSERT ON `admin` FOR EACH ROW BEGIN
    -- 检查手机号码格式
    IF LENGTH(NEW.phone_number) <> 11
    THEN
        SIGNAL SQLSTATE '45013' SET MESSAGE_TEXT = '电话号码长度不正确！';
    END IF;

    -- 检查密码长度
    IF LENGTH(NEW.password) < 6
    THEN
        SIGNAL SQLSTATE '45014' SET MESSAGE_TEXT = '密码长度不能小于6！';
    END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `check_admin_update` BEFORE UPDATE ON `admin` FOR EACH ROW BEGIN
    -- 检查手机号码格式
    IF LENGTH(NEW.phone_number) <> 11
    THEN
        SIGNAL SQLSTATE '45031' SET MESSAGE_TEXT = '电话号码长度不正确！';
    END IF;

    -- 检查密码长度
    IF LENGTH(NEW.password) < 6
    THEN
        SIGNAL SQLSTATE '45032' SET MESSAGE_TEXT = '密码长度不能小于6！';
    END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Temporary view structure for view `info_stu`
--

DROP TABLE IF EXISTS `info_stu`;
/*!50001 DROP VIEW IF EXISTS `info_stu`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `info_stu` AS SELECT 
 1 AS `stu_id`,
 1 AS `name`,
 1 AS `gender`,
 1 AS `age`,
 1 AS `email`,
 1 AS `phone_number`,
 1 AS `department`,
 1 AS `major`*/;
SET character_set_client = @saved_cs_client;

--
-- Temporary view structure for view `info_teacher`
--

DROP TABLE IF EXISTS `info_teacher`;
/*!50001 DROP VIEW IF EXISTS `info_teacher`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `info_teacher` AS SELECT 
 1 AS `tea_id`,
 1 AS `name`,
 1 AS `gender`,
 1 AS `age`,
 1 AS `email`,
 1 AS `phone_number`,
 1 AS `department`,
 1 AS `title`*/;
SET character_set_client = @saved_cs_client;

--
-- Temporary view structure for view `info_topic`
--

DROP TABLE IF EXISTS `info_topic`;
/*!50001 DROP VIEW IF EXISTS `info_topic`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `info_topic` AS SELECT 
 1 AS `topic_id`,
 1 AS `topic_title`,
 1 AS `tea_id`,
 1 AS `teacher_name`,
 1 AS `remaining_count`,
 1 AS `max_num`,
 1 AS `description`,
 1 AS `requirement`*/;
SET character_set_client = @saved_cs_client;

--
-- Table structure for table `selection`
--

DROP TABLE IF EXISTS `selection`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `selection` (
  `stu_id` char(8) NOT NULL,
  `topic_id` char(5) NOT NULL,
  `status` varchar(10) NOT NULL DEFAULT (_utf8mb4'审核中'),
  PRIMARY KEY (`stu_id`),
  KEY `topic_id` (`topic_id`),
  CONSTRAINT `selection_ibfk_1` FOREIGN KEY (`stu_id`) REFERENCES `student` (`stu_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `selection_ibfk_2` FOREIGN KEY (`topic_id`) REFERENCES `topic` (`topic_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `selection`
--

LOCK TABLES `selection` WRITE;
/*!40000 ALTER TABLE `selection` DISABLE KEYS */;
INSERT INTO `selection` VALUES ('20210001','00161','通过'),('20210002','00124','通过'),('20210003','00124','审核中'),('20210006','00131','审核中'),('20210010','00161','通过'),('20210011','00131','通过'),('20210012','00131','通过'),('20210013','00131','通过'),('20210014','00131','不通过'),('20210016','00124','通过'),('20210017','00121','审核中'),('20210018','00124','审核中'),('20210022','00123','审核中'),('20210024','00131','通过'),('20210025','00001','通过'),('20210026','00002','审核中'),('20210027','00003','不通过'),('20210028','00004','通过'),('20210029','00005','审核中'),('20210030','00006','不通过'),('20210031','00007','通过'),('20210032','00008','审核中'),('20210033','00009','审核中'),('20210034','00010','不通过'),('20210035','00011','通过'),('20210036','00012','审核中'),('20210037','00013','审核中'),('20210038','00014','不通过'),('20210039','00015','通过'),('20210040','00016','审核中'),('20210041','00121','不通过'),('20210042','00122','通过'),('20210043','00123','通过'),('20210044','00124','审核中'),('20210045','00125','不通过'),('20210046','00126','通过'),('20210047','00127','审核中'),('20210048','00128','通过'),('20210049','00129','审核中'),('20210050','00130','不通过'),('20210051','00131','通过'),('20210052','00132','审核中'),('20210053','00133','通过'),('20210054','00134','审核中'),('20210055','00135','不通过'),('20210056','00136','通过'),('20210057','00137','审核中'),('20210058','00138','审核中'),('20210059','00139','不通过'),('20210060','00140','审核中'),('20210061','00121','审核中'),('20210062','00122','不通过'),('20210063','00123','审核中'),('20210064','00124','不通过'),('20210065','00125','审核中'),('20210066','00126','通过'),('20210067','00127','通过'),('20210068','00128','审核中'),('20210069','00129','不通过'),('20210070','00130','审核中'),('20210071','00131','不通过'),('20210072','00132','通过'),('20210073','00133','通过'),('20210074','00134','审核中'),('20210075','00135','不通过'),('20210076','00136','通过'),('20210077','00137','审核中'),('20210078','00138','审核中'),('20210079','00139','不通过'),('20210085','00125','审核中'),('20210086','00126','通过'),('20210087','00127','通过'),('20210088','00128','审核中'),('20210089','00129','不通过'),('20210090','00130','审核中'),('20210091','00131','不通过'),('20210092','00132','通过'),('20210093','00133','通过'),('20210094','00134','审核中'),('20210095','00135','不通过'),('20210096','00136','通过'),('20210097','00137','审核中'),('20210098','00138','审核中'),('20210099','00139','不通过'),('20210100','00140','通过');
/*!40000 ALTER TABLE `selection` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `selection_after_insert` AFTER INSERT ON `selection` FOR EACH ROW BEGIN
    DECLARE curr_num INT;
    -- 查询当前题目已批准的选题数
    SELECT COUNT(*) INTO curr_num FROM Selection WHERE topic_id = NEW.topic_id AND status = '通过';
    -- 查询最大选题人数
    SELECT max_num INTO @max_num FROM Topic WHERE topic_id = NEW.topic_id;
    -- 如果已批准的选题数大于最大选题数，弹出错误信息，将插入操作回滚
    IF curr_num > @max_num THEN
        SIGNAL SQLSTATE '45036' SET MESSAGE_TEXT =
                '该话题选题人数已满！';
    END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `check_selection` BEFORE UPDATE ON `selection` FOR EACH ROW BEGIN
    -- 检查选题状态
    IF NEW.status NOT IN ('审核中', '不通过', '通过') THEN
        SIGNAL SQLSTATE '45017' SET MESSAGE_TEXT = '错误的审核状态！';
    END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `check_selection_update` BEFORE UPDATE ON `selection` FOR EACH ROW BEGIN
    -- 检查选题状态
    IF NEW.status NOT IN ('审核中', '不通过', '通过') THEN
        SIGNAL SQLSTATE '45035' SET MESSAGE_TEXT = '错误的审核状态！';
    END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `selection_after_update` AFTER UPDATE ON `selection` FOR EACH ROW BEGIN
    DECLARE curr_num INT;
    -- 查询当前题目已批准的选题数
    SELECT COUNT(*) INTO curr_num FROM Selection WHERE topic_id = NEW.topic_id AND status = '通过';
    -- 查询最大选题人数
    SELECT max_num INTO @max_num FROM Topic WHERE topic_id = NEW.topic_id;
    -- 如果已批准的选题数大于最大选题数，弹出错误信息，将插入操作回滚
    IF curr_num > @max_num THEN
        SIGNAL SQLSTATE '45036' SET MESSAGE_TEXT =
                '该话题选题人数已满！';
    END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Temporary view structure for view `stu_select`
--

DROP TABLE IF EXISTS `stu_select`;
/*!50001 DROP VIEW IF EXISTS `stu_select`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `stu_select` AS SELECT 
 1 AS `stu_id`,
 1 AS `stu_name`,
 1 AS `tea_id`,
 1 AS `tea_name`,
 1 AS `topic_title`,
 1 AS `topic_id`,
 1 AS `status`*/;
SET character_set_client = @saved_cs_client;

--
-- Temporary view structure for view `stu_teacher`
--

DROP TABLE IF EXISTS `stu_teacher`;
/*!50001 DROP VIEW IF EXISTS `stu_teacher`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `stu_teacher` AS SELECT 
 1 AS `tea_id`,
 1 AS `stu_id`,
 1 AS `name`,
 1 AS `gender`,
 1 AS `age`,
 1 AS `department`,
 1 AS `major`,
 1 AS `phone_number`,
 1 AS `email`*/;
SET character_set_client = @saved_cs_client;

--
-- Temporary view structure for view `stu_unselect`
--

DROP TABLE IF EXISTS `stu_unselect`;
/*!50001 DROP VIEW IF EXISTS `stu_unselect`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `stu_unselect` AS SELECT 
 1 AS `stu_id`,
 1 AS `name`,
 1 AS `department`,
 1 AS `major`,
 1 AS `phone_number`*/;
SET character_set_client = @saved_cs_client;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `student` (
  `stu_id` char(8) NOT NULL,
  `name` varchar(8) NOT NULL,
  `gender` varchar(6) NOT NULL,
  `age` smallint NOT NULL,
  `email` varchar(20) NOT NULL,
  `phone_number` varchar(20) NOT NULL,
  `department` varchar(10) NOT NULL,
  `major` varchar(10) NOT NULL,
  `password` varchar(20) NOT NULL DEFAULT '123456',
  PRIMARY KEY (`stu_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES ('20210001','张三','沃尔玛购物袋',19,'1345648974@qq.com','17539467521','计算机科学与技术','计算机科学与技术','123456'),('20210002','李星','女',18,'2154354423@qq.com','13547896324','计算机科学与技术','软件工程','123456'),('20210003','王富贵','男',19,'1486415321@qq.com','15384563246','计算机科学与技术','物联网工程','123456'),('20210004','赵子轩','男',19,'1486465453@qq.com','13895434213','网络空间安全','保密技术','123456'),('20210005','陈紫涵','女',20,'chenzihan@qq.com','13228734612','计算机科学与技术','软件工程','123456'),('20210006','王子涵','男',21,'wangzihan@qq.com','15117893431','计算机科学与技术','计算机科学与技术','123456'),('20210007','赵云飞','男',23,'zhaoyunfei@qq.com','15997846785','计算机科学与技术','数据科学与大数据技术','123456'),('20210008','李婷婷','女',22,'litingting@qq.com','15628731589','计算机科学与技术','人工智能','123456'),('20210009','刘少菲','女',20,'liushaofei@qq.com','13778451654','网络空间安全','信息安全','123456'),('20210010','马林潇','男',19,'malinxiao@qq.com','13967894562','计算机科学与技术','物联网工程','123456'),('20210011','宋嘉仪','女',22,'songjiayi@qq.com','13587684321','计算机科学与技术','计算机科学与技术','123456'),('20210012','郑倩倩','女',20,'zhengqianqian@qq.com','13768271823','计算机科学与技术','人工智能','123456'),('20210013','周红韵','女',23,'zhouhongyun@qq.com','15828739185','计算机科学与技术','数据科学与大数据技术','123456'),('20210014','吴双儿','女',21,'wushuanger@qq.com','13887678467','计算机科学与技术','计算机科学与技术','123456'),('20210015','张哲妍','女',22,'zhangzheyan@qq.com','18628731589','计算机科学与技术','人工智能','123456'),('20210016','孙洋洋','男',19,'sunyangyang@qq.com','15678946783','计算机科学与技术','物联网工程','123456'),('20210017','胡小齐','男',20,'huxiaoqi@qq.com','18928739576','网络空间安全','信息安全','123456'),('20210018','唐文静','女',21,'tangwenjing@qq.com','15898476473','计算机科学与技术','软件工程','123456'),('20210019','邓芷瑩','女',22,'dengzhiying@qq.com','13789435321','计算机科学与技术','物联网工程','123456'),('20210020','董浩','男',19,'donghao@qq.com','13888276451','网络空间安全','信息安全','123456'),('20210021','曹婷婷','女',21,'caotingting@qq.com','15178173454','计算机科学与技术','物联网工程','123456'),('20210022','李思琪','女',20,'lisiqi@qq.com','15978237145','计算机科学与技术','数据科学与大数据技术','123456'),('20210023','王子豪','男',22,'wangzihao@qq.com','15678174123','计算机科学与技术','人工智能','123456'),('20210024','张伟伟','男',20,'zhangweiwei@qq.com','13899874512','网络空间安全','保密技术','123456'),('20210025','李亮亮','男',21,'liliangliang@qq.com','13746239487','计算机科学与技术','物联网工程','123456'),('20210026','王喆','男',22,'wangzhe@qq.com','15234591328','网络空间安全','保密技术','123456'),('20210027','王静','女',22,'wangjing@qq.com','13964875643','计算机科学与技术','软件工程','123456'),('20210028','李强','男',23,'liqiang@qq.com','18976893475','网络空间安全','保密技术','123456'),('20210029','赵娜','女',19,'zhaona@qq.com','18712658746','计算机科学与技术','物联网工程','123456'),('20210030','朱敏','女',20,'zhumin@qq.com','13976823416','网络空间安全','保密技术','123456'),('20210031','刘强东','男',22,'liuqiangdong@qq.com','15628173654','计算机科学与技术','人工智能','123456'),('20210032','周涛','男',21,'zhoutao@qq.com','13878676584','网络空间安全','保密技术','123456'),('20210033','赵雪','女',23,'zhaoxue@qq.com','13787654201','计算机科学与技术','数据科学与大数据技术','123456'),('20210034','孙俪','女',19,'sunli@qq.com','18291827346','网络空间安全','保密技术','123456'),('20210035','张青','女',21,'zhangqing@qq.com','13898765324','计算机科学与技术','物联网工程','123456'),('20210036','刘旭','男',22,'liuxu@qq.com','15908675434','网络空间安全','保密技术','123456'),('20210037','刘莉','女',20,'liuli@qq.com','13675432698','计算机科学与技术','软件工程','123456'),('20210038','吕洋洋','男',21,'luyangyang@qq.com','13787654323','网络空间安全','保密技术','123456'),('20210039','王帅','男',19,'wangshuai@qq.com','15123456789','计算机科学与技术','人工智能','123456'),('20210040','王晓红','女',23,'wangxiaohong@qq.com','15876543218','网络空间安全','保密技术','123456'),('20210041','赵明','男',21,'zhaoming@qq.com','18734567890','计算机科学与技术','数据科学与大数据技术','123456'),('20210042','苏静','女',20,'suqing@qq.com','13987654567','网络空间安全','保密技术','123456'),('20210043','陆晨','女',21,'luchen@qq.com','13578462356','计算机科学与技术','物联网工程','123456'),('20210044','汪帅','男',19,'wangshuai@qq.com','15645372987','网络空间安全','保密技术','123456'),('20210045','曲羽','女',20,'quyu@qq.com','15621783947','计算机科学与技术','软件工程','123456'),('20210046','牛欣然','女',22,'niuxinran@qq.com','13573846921','网络空间安全','信息安全','123456'),('20210047','郑浩宇','男',23,'zhenghaoyu@qq.com','13546172994','计算机科学与技术','计算机科学与技术','123456'),('20210048','蔡天颖','女',21,'caitianying@qq.com','13984756123','网络空间安全','信息安全','123456'),('20210049','莫善言','男',20,'moshanyan@qq.com','13456729831','计算机科学与技术','人工智能','123456'),('20210050','管浩','男',22,'guanhao@qq.com','13918756423','网络空间安全','保密技术','123456'),('20210051','崔雪松','男',19,'cuixuesong@qq.com','13564738291','计算机科学与技术','软件工程','123456'),('20210052','易烨','女',21,'yiyi@qq.com','13102938475','网络空间安全','信息安全','123456'),('20210053','殷天正','男',20,'yintianzheng@qq.com','13502746189','计算机科学与技术','数据科学与大数据技术','123456'),('20210054','谢秋实','女',22,'xieqiushi@qq.com','13945618723','网络空间安全','保密技术','123456'),('20210055','苏宇杰','男',19,'suyujie@qq.com','13602981745','计算机科学与技术','计算机科学与技术','123456'),('20210056','钟丹妮','女',21,'zhongdanni@qq.com','13709264538','网络空间安全','信息安全','123456'),('20210057','傅志强','男',20,'fuzhiqiang@qq.com','13802735691','计算机科学与技术','软件工程','123456'),('20210058','谭淼','女',22,'tanmiao@qq.com','13904182635','网络空间安全','保密技术','123456'),('20210059','程鑫磊','男',19,'chengxinlei@qq.com','14001569847','计算机科学与技术','物联网工程','123456'),('20210060','罗美玲','女',21,'luomeiling@qq.com','14102857963','网络空间安全','信息安全','123456'),('20210061','邱子轩','男',20,'qiuzixuan@qq.com','14203964781','计算机科学与技术','软件工程','123456'),('20210062','钟梦洁','女',22,'zhongmengjie@qq.com','14302978563','网络空间安全','保密技术','123456'),('20210063','毛鹏','男',19,'maopeng@qq.com','14409876435','计算机科学与技术','数据科学与大数据技术','123456'),('20210064','司玉梅','女',21,'siyumei@qq.com','14502918327','网络空间安全','信息安全','123456'),('20210065','龚建平','男',20,'gongjianping@qq.com','14603849591','计算机科学与技术','计算机科学与技术','123456'),('20210066','孔超','女',22,'kongchao@qq.com','14709284567','网络空间安全','保密技术','123456'),('20210067','阎子豪','男',19,'yanzihao@qq.com','14805732943','计算机科学与技术','人工智能','123456'),('20210068','张倩倩','女',21,'zhangqianqian@qq.com','14901867325','网络空间安全','信息安全','123456'),('20210069','王磊','男',20,'wanglei@qq.com','15002784097','计算机科学与技术','软件工程','123456'),('20210070','赖梦婕','女',22,'laimengjie@qq.com','15103710689','网络空间安全','保密技术','123456'),('20210071','叶浩轩','男',19,'yehaoxuan@qq.com','15204638971','计算机科学与技术','物联网工程','123456'),('20210072','钟欣怡','女',21,'zhongxinyi@qq.com','15302578243','网络空间安全','信息安全','123456'),('20210073','陆建华','男',20,'lujianhua@qq.com','15406419587','计算机科学与技术','数据科学与大数据技术','123456'),('20210074','莫小冉','女',22,'moxiaoran@qq.com','15502356749','网络空间安全','保密技术','123456'),('20210075','司马浩然','男',19,'simahaoran@qq.com','15602847903','计算机科学与技术','计算机科学与技术','123456'),('20210076','杜天义','女',21,'dutianyi@qq.com','15701953065','网络空间安全','信息安全','123456'),('20210077','庄浩','男',20,'zhuanghao@qq.com','15802760219','计算机科学与技术','人工智能','123456'),('20210078','阎佳慧','女',22,'yanjiahui@qq.com','15909375381','网络空间安全','保密技术','123456'),('20210079','向军','男',19,'xiangjun@qq.com','16003186435','计算机科学与技术','软件工程','123456'),('20210080','郝梦洁','女',21,'haomengjie@qq.com','16102297487','网络空间安全','信息安全','123456'),('20210081','毕磊','男',20,'bilei@qq.com','16207380539','计算机科学与技术','数据科学与大数据技术','123456'),('20210082','钟欢','女',22,'zhonghuan@qq.com','16302647691','网络空间安全','保密技术','123456'),('20210083','宫浩宇','男',19,'gonghaoyu@qq.com','16409953843','计算机科学与技术','计算机科学与技术','123456'),('20210084','关嘉慧','女',21,'guanjiaohui@qq.com','16510286095','网络空间安全','信息安全','123456'),('20210085','毛建军','男',20,'maojianjun@qq.com','16607162347','计算机科学与技术','人工智能','123456'),('20210086','钱倩倩','女',22,'qianqianqian@qq.com','16704378599','网络空间安全','保密技术','123456'),('20210087','宋浩','男',19,'songhao@qq.com','16801694851','计算机科学与技术','软件工程','123456'),('20210088','叶慧敏','女',21,'yehuimin@qq.com','16902711093','网络空间安全','信息安全','123456'),('20210089','王建华','男',20,'wangjianhua@qq.com','17003647335','计算机科学与技术','物联网工程','123456'),('20210090','关倩','女',22,'guanqian@qq.com','17102945877','网络空间安全','保密技术','123456'),('20210091','宫志强','男',19,'gongzhiqiang@qq.com','17208752419','计算机科学与技术','数据科学与大数据技术','123456'),('20210092','钱雪','女',21,'qianxue@qq.com','17301795671','网络空间安全','信息安全','123456'),('20210093','毛建华','男',20,'maojianhua@qq.com','17404838923','计算机科学与技术','计算机科学与技术','123456'),('20210094','张泽灏','男',21,'zhangzehao@qq.com','17508722075','计算机科学与技术','数据科学与大数据技术','123456'),('20210095','李铭','男',19,'liming@qq.com','13546821564','计算机科学与技术','软件工程','123456'),('20210096','张晨阳','男',20,'zhangchenyang@qq.com','13978462356','计算机科学与技术','人工智能','123456'),('20210097','王思茜','女',21,'wangsixi@qq.com','15645376987','网络空间安全','信息安全','123456'),('20210098','宋承诺','男',19,'songchengnuo@qq.com','15621783457','计算机科学与技术','物联网工程','123456'),('20210099','陈思琪','女',22,'chensiqi@qq.com','13573846341','网络空间安全','保密技术','123456'),('20210100','黄泽雨','男',23,'huangzeyu@qq.com','13546171995','计算机科学与技术','数据科学与大数据技术','123456'),('20210101','高心语','女',21,'gaoxinyu@qq.com','13984756423','网络空间安全','信息安全','123456'),('20210102','孙悦','男',20,'sunyue@qq.com','13456723928','计算机科学与技术','软件工程','123456'),('20210103','李子君','女',22,'lizijun@qq.com','13918756450','网络空间安全','保密技术','123456'),('20210104','张志强','男',19,'zhangzhiqiang@qq.com','13564738241','计算机科学与技术','数据科学与大数据技术','123456'),('20210105','王浩天','男',21,'wanghaotian@qq.com','13102938470','网络空间安全','信息安全','123456'),('20210106','曹雪梅','女',20,'caoxuemei@qq.com','13502746987','计算机科学与技术','计算机科学与技术','123456'),('20210107','郭磊','男',22,'guolei@qq.com','13945618743','网络空间安全','保密技术','123456'),('20210108','陈加宜','女',21,'chenjiayi@qq.com','13602981756','计算机科学与技术','人工智能','123456'),('20210109','戴鑫','男',20,'daixin@qq.com','14409876445','网络空间安全','信息安全','123456'),('20210110','朱文卓','男',22,'zhuwenzhuo@qq.com','14502918323','计算机科学与技术','软件工程','123456'),('20210111','徐睿思','女',19,'xuruisi@qq.com','14603849560','网络空间安全','保密技术','123456'),('20210112','雷嘉欣','男',21,'leijiaxin@qq.com','14709284567','计算机科学与技术','数据科学与大数据技术','123456'),('20210113','肖怡菲','女',20,'xiaoyifei@qq.com','14805732932','网络空间安全','信息安全','123456'),('20210114','杨峰','男',22,'yangfeng@qq.com','14901867396','计算机科学与技术','计算机科学与技术','123456'),('20210115','李思琴','女',19,'lisiqin@qq.com','15002784032','网络空间安全','保密技术','123456'),('20210116','王浩健','男',21,'wanghaojian@qq.com','15103710634','计算机科学与技术','软件工程','123456'),('20210117','刘柳','女',20,'liuli@qq.com','15204638998','网络空间安全','信息安全','123456'),('20210118','孙彬','男',22,'sunbin@qq.com','15302578241','计算机科学与技术','数据科学与大数据技术','123456'),('20210119','杨洁','女',19,'yangjie@qq.com','15406419505','网络空间安全','保密技术','123456'),('20210120','李健','男',21,'lijian@qq.com','15502356794','计算机科学与技术','人工智能','123456'),('20210121','彭轩','男',20,'pengxuan@qq.com','15602847923','网络空间安全','信息安全','123456'),('20210122','实慧敏','女',22,'shihuimin@qq.com','15701953115','计算机科学与技术','物联网工程','123456'),('20210123','刘文博','男',19,'liuwenbo@qq.com','15802760287','网络空间安全','保密技术','123456'),('20210124','唐杨','女',21,'tangyang@qq.com','15909375349','计算机科学与技术','软件工程','123456'),('20210125','林浩','男',20,'linhao@qq.com','16003186400','网络空间安全','信息安全','123456'),('20210126','王晨','女',21,'wangchen@qq.com','13578462356','计算机科学与技术','物联网工程','123465'),('20210127','陈阳','男',22,'chenyang@qq.com','13789234761','网络空间安全','信息安全','123465'),('20210128','李芳','女',20,'lifang@qq.com','13987651234','计算机科学与技术','数据科学与大数据技术','123465'),('20210129','赵雪','女',23,'zhaoxue@qq.com','13876549872','网络空间安全','信息安全','123465'),('20210130','许建','男',22,'xujian@qq.com','15645376987','计算机科学与技术','人工智能','123465'),('20210131','张晨阳','男',20,'zhangchenyang@qq.com','13978462356','计算机科学与技术','人工智能','123456'),('20210132','王思茜','女',21,'wangsixi@qq.com','15645376987','网络空间安全','信息安全','123456'),('20210133','宋承诺','男',19,'songchengnuo@qq.com','15621783457','计算机科学与技术','物联网工程','123456'),('20210134','赵梦','女',20,'zhaomeng@qq.com','13798761234','计算机科学与技术','软件工程','123465'),('20210135','钱志远','男',22,'qianzhiyuan@qq.com','13987651235','网络空间安全','信息安全','123465'),('20210136','孙晓峰','男',21,'sunxiaofeng@qq.com','15876549876','计算机科学与技术','数据科学与大数据技术','123465'),('20210137','李红梅','女',19,'lihongmei@qq.com','15876452345','计算机科学与技术','人工智能','123465'),('20210138','周飞扬','男',23,'zhoufeiyang@qq.com','13798234567','网络空间安全','信息安全','123465'),('20210139','吴若曦','女',20,'wuruoxi@qq.com','13876543210','计算机科学与技术','物联网工程','123465'),('20210140','郑宇轩','男',22,'zhengyuxuan@qq.com','15987651234','计算机科学与技术','软件工程','123465'),('20210141','王诗婷','女',21,'wangshiting@qq.com','13678763456','网络空间安全','信息安全','123465'),('20210142','冯军','男',23,'fengjun@qq.com','13598761234','计算机科学与技术','数据科学与大数据技术','123465'),('20210143','陈婷','女',20,'chenting@qq.com','15876549876','计算机科学与技术','人工智能','123465'),('20210144','董浩','男',21,'donghao@qq.com','13787654321','网络空间安全','物联网工程','123465'),('20210145','张悦','女',20,'zhangyue@qq.com','13876549876','计算机科学与技术','软件工程','123465'),('20210146','王鹏飞','男',22,'wangpengfei@qq.com','13678763456','网络空间安全','信息安全','123465'),('20210147','李琳','女',21,'lilin@qq.com','13598761234','计算机科学与技术','数据科学与大数据技术','123465'),('20210148','赵泽宇','男',19,'zhaozeyu@qq.com','13787654321','网络空间安全','人工智能','123465'),('20210149','孙雪','女',23,'sunxue@qq.com','15987651234','计算机科学与技术','物联网工程','123465'),('20210150','钱明','男',20,'qianming@qq.com','15876543210','计算机科学与技术','软件工程','123465'),('20210151','周艺','女',22,'zhouyi@qq.com','13798234567','网络空间安全','信息安全','123465'),('20210152','吴涛','男',21,'wutao@qq.com','13987651235','计算机科学与技术','数据科学与大数据技术','123465'),('20210153','郑梦','女',23,'zhengmeng@qq.com','13798761234','计算机科学与技术','人工智能','123465'),('20210154','王浩','男',20,'wanghao@qq.com','13876549876','网络空间安全','物联网工程','123465'),('20210155','张新','男',22,'zhangxin@qq.com','13678763456','计算机科学与技术','软件工程','123465'),('20210156','王蓉','女',21,'wangrong@qq.com','13598761234','网络空间安全','信息安全','123465'),('20210157','李岩','男',19,'liyan@qq.com','13787654321','计算机科学与技术','数据科学与大数据技术','123465'),('20210158','赵晓霞','女',23,'zhaoxiaoxia@qq.com','15987651234','网络空间安全','人工智能','123465'),('20210159','孙杰','男',20,'sunjie@qq.com','15876543210','计算机科学与技术','物联网工程','123465'),('20210160','钱晓丽','女',22,'qianxiaoli@qq.com','13798234567','计算机科学与技术','软件工程','123465'),('20210161','周晨','男',21,'zhouchen@qq.com','13987651235','网络空间安全','信息安全','123465'),('20210162','吴浩然','男',23,'wuhaoran@qq.com','13798761234','计算机科学与技术','数据科学与大数据技术','123465'),('20210163','郑婷婷','女',20,'zhengtingting@qq.com','15876549876','计算机科学与技术','人工智能','123465'),('20210164','王奇','男',21,'wangqi@qq.com','13678763456','网络空间安全','物联网工程','123465'),('20210165','李宇航','男',22,'liyuhang@qq.com','13598761234','计算机科学与技术','软件工程','123465'),('20210166','赵婷','女',19,'zhaoting@qq.com','13787654321','网络空间安全','信息安全','123465'),('20210167','孙宇轩','男',23,'sunyuxuan@qq.com','15987651234','计算机科学与技术','数据科学与大数据技术','123465'),('20210168','钱雅梦','女',20,'qianyameng@qq.com','15876543210','计算机科学与技术','人工智能','123465'),('20210169','周梦琪','女',22,'zhoumengqi@qq.com','13798234567','网络空间安全','物联网工程','123465'),('20210170','吴雪','女',21,'wuxue@qq.com','13987651235','计算机科学与技术','软件工程','123465'),('20210171','郑一鸣','男',23,'zhengyiming@qq.com','13798761234','网络空间安全','信息安全','123465'),('20210172','王梓','男',20,'wangzi@qq.com','13678763456','计算机科学与技术','数据科学与大数据技术','123465'),('20210173','李思思','女',21,'lisisi@qq.com','13598761234','计算机科学与技术','人工智能','123465'),('20210174','赵梦婷','女',19,'zhaomengting@qq.com','13787654321','网络空间安全','物联网工程','123465'),('20210175','孙思宇','男',21,'sunsy@qq.com','15987651234','计算机科学与技术','软件工程','123465'),('20210176','张悠悠','女',20,'zhangyouyou@qq.com','13876549876','计算机科学与技术','软件工程','123465'),('20210177','王阳','男',22,'wangyang@qq.com','13678763456','网络空间安全','信息安全','123465'),('20210178','李雨萌','女',21,'liyumeng@qq.com','13598761234','计算机科学与技术','数据科学与大数据技术','123465'),('20210179','赵子宇','男',19,'zhaoziyu@qq.com','13787654321','网络空间安全','人工智能','123465'),('20210180','孙雨萌','女',23,'sunyumeng@qq.com','15987651234','计算机科学与技术','物联网工程','123465'),('20210181','钱梓宇','男',20,'qianziyu@qq.com','15876543210','计算机科学与技术','软件工程','123465'),('20210182','周一鸣','男',21,'zhouyiming@qq.com','13987651235','网络空间安全','信息安全','123465'),('20210183','吴梓','男',23,'wuzi@qq.com','13798761234','计算机科学与技术','数据科学与大数据技术','123465'),('20210184','郑思宇','女',20,'zhengsiyu@qq.com','15876549876','计算机科学与技术','人工智能','123465'),('20210185','王雨婷','女',21,'wangyuting@qq.com','13678763456','网络空间安全','物联网工程','123465'),('20210186','李思雨','男',22,'lisiyu@qq.com','13598761234','计算机科学与技术','软件工程','123465'),('20210187','赵晨曦','女',19,'zhaochenxi@qq.com','13787654321','网络空间安全','信息安全','123465'),('20210188','孙晨曦','男',23,'sunchenxi@qq.com','15987651234','计算机科学与技术','数据科学与大数据技术','123465'),('20210189','钱晨晨','女',20,'qianchenchen@qq.com','15876543210','计算机科学与技术','人工智能','123465'),('20210190','周晓宇','女',22,'zhouxiaoyu@qq.com','13798234567','网络空间安全','物联网工程','123465'),('20210191','吴晓雨','男',21,'wuxiaoyu@qq.com','13987651235','计算机科学与技术','软件工程','123465'),('20210192','郑晨晨','男',23,'zhengchenchen@qq.com','13798761234','网络空间安全','信息安全','123465'),('20210193','王雨婷','女',20,'wangyuting@qq.com','13678763456','计算机科学与技术','数据科学与大数据技术','123465'),('20210194','李晨曦','女',21,'lichenxi@qq.com','13598761234','计算机科学与技术','人工智能','123465'),('20210195','赵曦曦','男',19,'zhaoxixi@qq.com','13787654321','网络空间安全','物联网工程','123465'),('20210196','孙晨宇','男',21,'sunchenyu@qq.com','15987651234','计算机科学与技术','软件工程','123465'),('20210197','李晨宇','女',20,'lichenyu@qq.com','13678763456','计算机科学与技术','人工智能','123465'),('20210198','赵晨宇','男',22,'zhaochenyu@qq.com','13598761234','网络空间安全','物联网工程','123465');
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `check_student` BEFORE INSERT ON `student` FOR EACH ROW BEGIN
    -- 检查邮箱格式
    IF NEW.email NOT LIKE '%@%.com'
    THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = '邮箱格式错误！';
    END IF;

    -- 检查手机号码格式
    IF LENGTH(NEW.phone_number) <> 11
    THEN
        SIGNAL SQLSTATE '45001' SET MESSAGE_TEXT = '电话号码长度不正确！';
    END IF;

    -- 检查密码长度
    IF LENGTH(NEW.password) < 6
    THEN
        SIGNAL SQLSTATE '45002' SET MESSAGE_TEXT = '密码长度不能小于6！';
    END IF;

    -- 检查学号长度
    IF LENGTH(NEW.stu_id) <> 8 THEN
        SIGNAL SQLSTATE '45003' SET MESSAGE_TEXT = '学号必须为8位！';
    END IF;

    -- 检查年龄范围
    IF NEW.age < 16 OR NEW.age > 65 THEN
        SIGNAL SQLSTATE '45004' SET MESSAGE_TEXT = '年龄错误！应该在16-65之间';
    END IF;

    -- 检查性别
    IF NEW.gender NOT IN ('男', '女', '沃尔玛购物袋', '大润发购物袋')
    THEN
        SIGNAL SQLSTATE '45005' SET MESSAGE_TEXT = '性别错误！';
    END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `check_student_update` BEFORE UPDATE ON `student` FOR EACH ROW BEGIN
    -- 检查邮箱格式
    IF NEW.email NOT LIKE '%@%.com'
    THEN
        SIGNAL SQLSTATE '45018' SET MESSAGE_TEXT = '邮箱格式错误！';
    END IF;

    -- 检查手机号码格式
    IF LENGTH(NEW.phone_number) <> 11
    THEN
        SIGNAL SQLSTATE '45019' SET MESSAGE_TEXT = '电话号码长度不正确！';
    END IF;

    -- 检查密码长度
    IF LENGTH(NEW.password) < 6
    THEN
        SIGNAL SQLSTATE '45020' SET MESSAGE_TEXT = '密码长度不能小于6！';
    END IF;

    -- 检查学号长度
    IF LENGTH(NEW.stu_id) <> 8 THEN
        SIGNAL SQLSTATE '45021' SET MESSAGE_TEXT = '学号必须为8位！';
    END IF;

    -- 检查年龄范围
    IF NEW.age < 16 OR NEW.age > 65 THEN
        SIGNAL SQLSTATE '45022' SET MESSAGE_TEXT = '年龄错误！应该在30-65之间';
    END IF;

    -- 检查性别
    IF NEW.gender NOT IN ('男', '女', '沃尔玛购物袋', '大润发购物袋')
    THEN
        SIGNAL SQLSTATE '45023' SET MESSAGE_TEXT = '性别错误！';
    END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `teacher`
--

DROP TABLE IF EXISTS `teacher`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `teacher` (
  `tea_id` char(8) NOT NULL,
  `name` varchar(8) NOT NULL,
  `gender` varchar(6) NOT NULL,
  `age` smallint NOT NULL,
  `email` varchar(20) NOT NULL,
  `phone_number` varchar(20) NOT NULL,
  `department` varchar(10) NOT NULL,
  `title` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL DEFAULT '123456',
  PRIMARY KEY (`tea_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `teacher`
--

LOCK TABLES `teacher` WRITE;
/*!40000 ALTER TABLE `teacher` DISABLE KEYS */;
INSERT INTO `teacher` VALUES ('20210001','阿铭','大润发购物袋',35,'1285280778@qq.com','13457489603','计算机科学与技术','讲师','123456'),('20210002','邓面生','男',51,'2051321487@qq.com','15216341846','计算机科学与技术','教授','123456'),('20210003','王壮','男',43,'wangzhuang@qq.com','19745218462','计算机科学与技术','副教授','123456'),('20210004','李丽','女',50,'lili@qq.com','13898277351','计算机科学与技术','教授','123456'),('20210005','张峰','男',30,'zhangfeng@qq.com','13767293857','网络空间安全','讲师','123456'),('20210006','赵俊杰','男',38,'zhaojunjie@qq.com','15718263844','计算机科学与技术','副教授','123456'),('20210007','陈慧娟','女',51,'chenhuijuan@qq.com','13995867845','网络空间安全','教授','123456'),('20210008','王涛','男',36,'wangtao@qq.com','15098263217','计算机科学与技术','副教授','123456'),('20210009','刘芳','女',28,'liufang@qq.com','18063245851','网络空间安全','讲师','123456'),('20210010','张三','男',45,'zhangsan@qq.com','15682913328','计算机科学与技术','教授','123456'),('20210011','王小燕','女',48,'wangxiaoyan@qq.com','13698221237','网络空间安全','教授','123456'),('20210012','孙杰','男',42,'sunjie@qq.com','13985627984','计算机科学与技术','副教授','123456'),('20210013','赵梅','女',30,'zhaomei@qq.com','15729388928','网络空间安全','讲师','123456'),('20210014','李明','男',56,'liming@qq.com','18682912513','计算机科学与技术','教授','123456'),('20210015','王梅','女',39,'wangmei@qq.com','13098227129','网络空间安全','副教授','123456'),('20210016','张文华','男',33,'zhangwenhua@qq.com','13985331281','计算机科学与技术','讲师','123456'),('20210017','张明','男',45,'zhangming@qq.com','13578462356','计算机科学与技术','教授','123465'),('20210018','王丽','女',39,'wangli@qq.com','13789234761','网络空间安全','副教授','123465'),('20210019','李华','男',34,'lihua@qq.com','13987651234','计算机科学与技术','讲师','123465'),('20210020','赵秀','女',42,'zhaoxiu@qq.com','13876549872','计算机科学与技术','教授','123465'),('20210021','孙艳','女',36,'sunyan@qq.com','15876452345','网络空间安全','副教授','123465'),('20210022','钱刚','男',40,'qiang@qq.com','13876543210','计算机科学与技术','教授','123465'),('20210023','周丽芳','女',38,'zhoulihua@qq.com','15987651234','计算机科学与技术','讲师','123465'),('20210024','吴建国','男',43,'wujian_guo@qq.com','15645376987','网络空间安全','教授','123465'),('20210025','郑婷婷','女',37,'zhengtingting@qq.com','13798234567','计算机科学与技术','副教授','123465'),('20210026','黄新','男',41,'huangxin@qq.com','13787654321','网络空间安全','讲师','123465'),('20210027','徐梦','女',35,'xumeng@qq.com','15987651234','计算机科学与技术','教授','123465'),('20210028','赵美丽','女',40,'zhaomeili@qq.com','13598761234','网络空间安全','讲师','123465'),('20210029','孙建宇','男',35,'sunjianyu@qq.com','13787654321','计算机科学与技术','教授','123465'),('20210030','钱梦雅','女',43,'qianmengya@qq.com','15987651234','网络空间安全','副教授','123465'),('20210031','周文','男',38,'zhouwenhua@qq.com','15876549876','计算机科学与技术','讲师','123465'),('20210032','吴艳芳','女',42,'wuyanfang@qq.com','13798234567','网络空间安全','教授','123465'),('20210033','郑刚毅','男',36,'zhenggangyi@qq.com','13678763456','计算机科学与技术','副教授','123465'),('20210034','黄丽梅','女',41,'huanglimei@qq.com','13598761234','网络空间安全','讲师','123465'),('20210035','徐刚明','男',37,'xugangming@qq.com','13787654321','计算机科学与技术','教授','123465'),('20210036','孟艳秋','女',44,'mengyanqiu@qq.com','15987651234','网络空间安全','副教授','123465'),('20210037','赵艳丽','女',45,'zhaoyanli@qq.com','15987651234','网络空间安全','教授','123465'),('20210038','孙新宇','男',39,'sunxinyu@qq.com','13876549872','计算机科学与技术','副教授','123465'),('20210039','钱梦瑶','女',36,'qianmengyao@qq.com','13678763456','网络空间安全','讲师','123465'),('20210040','周建华','男',44,'zhoujianhua@qq.com','13598761234','计算机科学与技术','教授','123465'),('20210041','吴艳霞','女',38,'wuyanxia@qq.com','13787654321','网络空间安全','副教授','123465'),('20210042','郑刚勇','男',40,'zhenggangyong@qq.com','15876452345','计算机科学与技术','讲师','123465'),('20210043','黄丽华','女',35,'huanglihua@qq.com','13798761234','网络空间安全','教授','123465'),('20210044','徐刚毅','男',43,'xugangyi@qq.com','15987651234','计算机科学与技术','副教授','123465'),('20210045','李秋玲','女',37,'mengyanqiu@qq.com','13876549876','网络空间安全','讲师','123465'),('20210046','顾建宇','男',42,'gujianyu@qq.com','13678763456','计算机科学与技术','教授','123465'),('20210095','铭铭','男',55,'mingming@qq.com','15486215437','计算机科学与技术','教授','123456');
/*!40000 ALTER TABLE `teacher` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `check_teacher` BEFORE INSERT ON `teacher` FOR EACH ROW BEGIN
    -- 检查邮箱格式
    IF NEW.email NOT LIKE '%@%.com'
    THEN
        SIGNAL SQLSTATE '45006' SET MESSAGE_TEXT = '邮箱格式错误！';
    END IF;

    -- 检查手机号码格式
    IF LENGTH(NEW.phone_number) <> 11
    THEN
        SIGNAL SQLSTATE '45007' SET MESSAGE_TEXT = '电话号码长度不正确！';
    END IF;

    -- 检查密码长度
    IF LENGTH(NEW.password) < 6
    THEN
        SIGNAL SQLSTATE '45008' SET MESSAGE_TEXT = '密码长度不能小于6！';
    END IF;

    -- 检查教师号长度
    IF LENGTH(NEW.tea_id) <> 8
    THEN
        SIGNAL SQLSTATE '45009' SET MESSAGE_TEXT = '教师号必须为8位！';
    END IF;

    -- 检查年龄范围
    IF NEW.age < 20 OR NEW.age > 65
    THEN
        SIGNAL SQLSTATE '45010' SET MESSAGE_TEXT = '年龄错误!应该在20-65之间';
    END IF;

    -- 检查性别
    IF NEW.gender NOT IN ('男', '女', '沃尔玛购物袋', '大润发购物袋')
    THEN
        SIGNAL SQLSTATE '45011' SET MESSAGE_TEXT = '性别错误！';
    END IF;

    -- 检查职称
    IF NEW.title NOT IN ('教授', '副教授', '讲师')
    THEN
        SIGNAL SQLSTATE '45012' SET MESSAGE_TEXT = '职称错误！';
    END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `check_teacher_update` BEFORE UPDATE ON `teacher` FOR EACH ROW BEGIN
    -- 检查邮箱格式
    IF NEW.email NOT LIKE '%@%.com'
    THEN
        SIGNAL SQLSTATE '45024' SET MESSAGE_TEXT = '邮箱格式错误！';
    END IF;

    -- 检查手机号码格式
    IF LENGTH(NEW.phone_number) <> 11
    THEN
        SIGNAL SQLSTATE '45025' SET MESSAGE_TEXT = '电话号码长度不正确！';
    END IF;

    -- 检查密码长度
    IF LENGTH(NEW.password) < 6
    THEN
        SIGNAL SQLSTATE '45026' SET MESSAGE_TEXT = '密码长度不能小于6！';
    END IF;

    -- 检查教师号长度
    IF LENGTH(NEW.tea_id) <> 8
    THEN
        SIGNAL SQLSTATE '45027' SET MESSAGE_TEXT = '教师号必须为8位！';
    END IF;

    -- 检查年龄范围
    IF NEW.age < 20 OR NEW.age > 65
    THEN
        SIGNAL SQLSTATE '45028' SET MESSAGE_TEXT = '年龄错误!应该在20-65之间';
    END IF;

    -- 检查性别
    IF NEW.gender NOT IN ('男', '女', '沃尔玛购物袋', '大润发购物袋')
    THEN
        SIGNAL SQLSTATE '45029' SET MESSAGE_TEXT = '性别错误！';
    END IF;

    -- 检查职称
    IF NEW.title NOT IN ('教授', '副教授', '讲师')
    THEN
        SIGNAL SQLSTATE '45030' SET MESSAGE_TEXT = '职称错误！';
    END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `topic`
--

DROP TABLE IF EXISTS `topic`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `topic` (
  `topic_id` varchar(5) NOT NULL,
  `tea_id` char(12) NOT NULL,
  `topic_title` varchar(50) NOT NULL,
  `description` text NOT NULL,
  `requirement` text NOT NULL,
  `max_num` smallint NOT NULL,
  PRIMARY KEY (`topic_id`),
  KEY `tea_id` (`tea_id`),
  CONSTRAINT `topic_ibfk_1` FOREIGN KEY (`tea_id`) REFERENCES `teacher` (`tea_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `topic`
--

LOCK TABLES `topic` WRITE;
/*!40000 ALTER TABLE `topic` DISABLE KEYS */;
INSERT INTO `topic` VALUES ('00001','20210005','开发基于机器学习的智能推荐系统','该课题旨在研究并实现基于机器学习算法的个性化推荐系统，提高用户体验和推荐准确度。','要求学生具备扎实的机器学习基础，熟悉常见推荐算法，具有良好的编程能力，熟悉大数据处理技术。',5),('00002','20210015','设计并实现区块链智能合约','本课题旨在研究智能合约的设计和实现，结合区块链技术，实现可靠的智能合约应用。','要求学生具备区块链和智能合约基础知识，熟悉以太坊、Solidity等相关技术，具有良好的代码编写能力。',3),('00003','20210030','基于深度学习的图像生成研究','该课题旨在探索深度学习技术在图像生成领域的应用，包括生成对抗网络（GAN）等相关算法。','要求学生具备深度学习基础知识，熟悉图像生成算法，具有良好的实验和分析能力。',6),('00004','20210022','开发智能家居控制系统','本课题旨在设计和实现智能家居系统，包括传感器数据采集、智能控制算法和用户界面的开发。','要求学生熟悉物联网技术，具备嵌入式系统开发经验，熟悉常见的传感器和控制技术。',4),('00005','20210040','基于大数据的网络流量分析与优化','该课题旨在研究大数据技术在网络流量分析和优化中的应用，以提升网络性能和安全性。','要求学生具备扎实的大数据处理和分析技能，了解网络协议和安全基础知识，熟悉流量分析工具和方法。',5),('00006','20210012','开发智能语音识别系统','本课题旨在设计和实现基于深度学习的智能语音识别系统，提高语音识别的准确性和实时性。','要求学生具备深度学习和语音信号处理基础，熟悉常见的语音识别算法，具有良好的编程能力。',5),('00007','20210025','智能城市交通管理系统设计','该课题旨在研究并设计基于物联网和大数据的智能城市交通管理系统，提高交通运行效率。','要求学生熟悉物联网技术和大数据处理，具备嵌入式系统开发经验，熟悉交通流理论。',4),('00008','20210032','基于区块链的数字身份认证系统','本课题旨在研究区块链技术在数字身份认证领域的应用，设计安全可靠的身份认证系统。','要求学生具备区块链和网络安全基础知识，熟悉数字身份认证协议，具有良好的编程能力。',6),('00009','20210009','智能健康监测与数据分析','该课题旨在研究和开发智能健康监测系统，结合传感器技术和大数据分析，提高用户健康管理水平。','要求学生熟悉嵌入式系统开发，具备传感器数据处理经验，了解健康数据分析方法。',5),('00010','20210018','软件定义网络（SDN）的性能优化','本课题旨在研究软件定义网络中的性能瓶颈，并提出优化策略，以提升网络性能和可管理性。','要求学生熟悉网络协议和SDN基础知识，具备网络性能分析和调优经验，熟悉OpenFlow等相关技术。',4),('00011','20210038','基于深度学习的智能视频分析系统','该课题旨在研究深度学习技术在视频分析领域的应用，包括目标检测、行为识别等方面。','要求学生具备深度学习基础知识，熟悉计算机视觉算法，具有良好的实验和分析能力。',6),('00012','20210029','智能农业物联网系统设计','本课题旨在研究并设计基于物联网技术的智能农业系统，提高农业生产效率和资源利用率。','要求学生熟悉物联网技术，具备嵌入式系统开发经验，了解农业信息化技术。',5),('00013','20210044','移动边缘计算在智能城市中的应用','该课题旨在研究移动边缘计算技术在智能城市场景中的应用，提高数据处理效率和响应速度。','要求学生熟悉边缘计算和网络技术，具备相关应用开发经验，熟悉移动边缘计算框架。',6),('00014','20210015','基于人工智能的医学图像诊断系统','本课题旨在研究并设计基于人工智能的医学图像诊断系统，提高诊断准确性和效率。','要求学生具备人工智能和医学图像处理基础知识，熟悉深度学习算法，具有良好的编程能力。',5),('00015','20210030','基于大数据的社交媒体情感分析','该课题旨在研究大数据技术在社交媒体情感分析中的应用，了解用户情感和舆情。','要求学生具备扎实的大数据处理和分析技能，熟悉情感分析算法，具有良好的实验和分析能力。',4),('00016','20210003','智能化电力系统监控与管理','本课题旨在研究智能化电力系统监控与管理方案，提高电力系统的稳定性和可靠性。','要求学生熟悉电力系统基础知识，具备相关监控与管理系统开发经验，熟悉相关标准与规范。',5),('00017','20210017','智能医疗影像诊断系统','该课题旨在研究并实现基于深度学习的医疗影像诊断系统，提高医生的诊断准确性。','要求学生具备深度学习和医学影像处理基础知识，熟悉医学领域的临床需求。',5),('00018','20210022','智能化智能家居控制系统设计','本课题旨在设计智能化智能家居控制系统，实现智能家居设备的联动和自动控制。','要求学生熟悉物联网技术，具备嵌入式系统开发经验，了解智能家居协议。',6),('00019','20210030','基于人工智能的语音翻译应用','该课题旨在研究并开发基于人工智能的语音翻译应用，实现多语言之间的实时翻译。','要求学生具备语音信号处理和机器学习基础知识，熟悉自然语言处理算法。',5),('00020','20210003','智能化交通管理系统设计','本课题旨在设计智能化交通管理系统，利用物联网和大数据技术提高交通流畅度。','要求学生熟悉物联网技术和大数据分析，具备交通流理论基础知识。',4),('00021','20210009','智能化农业监控系统研究','该课题旨在研究智能化农业监控系统，结合传感器和数据分析技术，提高农业生产效益。','要求学生熟悉物联网技术，了解农业生产流程，具备相关系统开发经验。',5),('00022','20210014','虚拟现实（VR）在旅游行业的应用','本课题旨在研究虚拟现实技术在旅游行业中的应用，设计沉浸式的虚拟旅游体验。','要求学生熟悉虚拟现实技术，具备应用开发经验，了解旅游行业需求。',6),('00023','20210033','智能化能源管理系统设计','该课题旨在设计智能化能源管理系统，利用大数据和物联网技术提高能源利用效率。','要求学生熟悉物联网技术和大数据分析，了解能源管理领域的相关知识。',5),('00024','20210007','基于区块链的供应链溯源系统研究','本课题旨在研究区块链技术在供应链溯源中的应用，提高产品的追溯能力。','要求学生熟悉区块链技术，具备供应链管理基础知识，熟悉智能合约的编写。',4),('00025','20210028','智能化智慧城市规划与设计','该课题旨在研究智能化智慧城市的规划与设计，结合物联网和大数据技术提高城市管理水平。','要求学生熟悉城市规划和设计原理，具备相关系统开发经验，了解智慧城市概念。',6),('00026','20210001','人工智能在医疗辅助诊断中的应用','本课题旨在研究人工智能在医疗影像诊断中的应用，提高医生的诊断效率和准确性。','要求学生具备深度学习和医学影像处理基础知识，熟悉医疗领域的临床需求。',5),('00027','20210009','智能化金融投资决策系统设计','该课题旨在设计智能化金融投资决策系统，利用大数据和机器学习技术提高投资决策水平。','要求学生熟悉大数据分析和机器学习技术，了解金融投资领域的相关知识。',4),('00121','20210002','校园教务管理系统','为了更新学校的教务系统，请你设计一个教务管理系统，帮助学生教师更好地使用。','开发一个Web端的教务管理系统，能够在校园网内访问。学生能查看自己的信息，考试报名，查看选课...教师能查看自己的信息，查看自己的课程，并且查看该课程的学生。完成一篇论文，展示设计成果。',3),('00122','20210002','图书管理系统','做出图书管理系统的需求分析，概念结构分析，逻辑结构分析，数据库的实施及维护。','1 进行新书入库、现有图书信息修改以及删除； ② 能够实现对读者基本信息的查询和编辑管理； ③ 能够实现预约功能； ④ 能够实现借阅信息的查询功能； ',4),('00123','20210001','学生会干部信息管理系统','做出学生会干部信息管理系统的需求分析，概念结构分析，逻辑结构分析，数据库的实施及维护。 ','1 进行学生会干部信息的录入修改及删除；② 能够实现对干部基本信息的查询； ③ 能够进行学生会活动组织和相关干部的职责分配； ④ 能够根据学生会干部的工作情况打分，并以学期为单位进行统计； ',4),('00124','20210001','毕业设计选题系统','做出毕业设计选题系统的需求分析，概念结构分析，逻辑结构分析，数据库的实施及维护。','1学生可以在选题功能模块中浏览到自己心仪的题目并且选择该题目，之后等待出题老师录取。每个学生只能选择一条题目。 \n在老师没有录取之前学生能退掉自己已经选择的题目并且重新选择。 \n学生能修改自己注册时的个人信息，方便信息更新准确。 \n2教师功能： \n教师可以查询到已经选择了自己建立的题目的学生，并且有权利根据学生具体情况决定是否录取或是退选。 \n教师可以建立新题目供学生选择。 \n教师可以修改自己已经建立的题目信息，确保信息的准确性。 \n教师可以修改自己的注册资料，确保个人信息的准确性。 \n3管理员功能： 管理员可以查看、修改和删除系统内的所有学生个人信息，教师个人信息，所有题目的信息。\n 管理员可以通过可选题目的查询，待录取题目的查询和已录取题目的查询了解整个毕业论文的总体工作进展情况 ',2),('00125','20210019','移动设备上的智能健康管理应用','该课题旨在研究并开发基于移动设备的智能健康管理应用，实现健康数据的实时监测与分析。','要求学生熟悉移动应用开发，具备健康数据处理经验，熟悉相关健康管理算法。',6),('00126','20210028','区块链在供应链管理中的应用','本课题旨在研究区块链技术在供应链管理中的应用，提高供应链的透明度和效率。','要求学生熟悉区块链技术，具备供应链管理基础知识，熟悉智能合约开发。',5),('00127','20210014','智能家居安全性分析与防护','该课题旨在研究智能家居系统的安全性问题，并提出相应的安全防护措施。','要求学生熟悉网络安全基础知识，具备嵌入式系统开发经验，熟悉智能家居协议。',4),('00128','20210033','语音情感识别在客户服务中的应用','本课题旨在研究语音情感识别技术在客户服务领域的应用，提高服务质量与用户体验。','要求学生具备语音信号处理基础知识，熟悉情感识别算法，具有良好的编程能力。',3),('00129','20210007','基于深度学习的远程医疗诊断系统','该课题旨在研究深度学习技术在远程医疗诊断中的应用，实现医学影像的自动诊断。','要求学生具备深度学习和医学图像处理基础知识，熟悉相关医疗数据标准，具有实际医学背景者优先。',5),('00130','20210024','智能化校园安全监控系统设计','本课题旨在设计智能化校园安全监控系统，结合视频分析和物联网技术，提高校园安全水平。','要求学生熟悉视频分析和物联网技术，具备嵌入式系统开发经验，熟悉相关安防技术。',6),('00131','20210007','基于网络的彩票购买抽奖程序','总体功能类似等级B的“彩票购买抽奖程序”，分为服务器端和客户端。 ','服务器端功能： \na.用户注册         \nb.记录用户所购彩票记录             c.如果用户中奖，通知中奖用户 \nd.摇奖(期号--当期号码)         e.统计当期购买彩票的金额 \n客户端功能：(模拟手机的QQ彩票客户端) \na.用户登陆         \nb.充值          \nc.购买彩票         \nd.购彩记录         \ne.中将提醒(登陆后提醒) \n测试：同等级B的“彩票购买抽奖程序”的第5点要求。 \n注意：服务器端使用多线程，同时接受多个客户端购买彩票。 ',5),('00132','20210007','聊天室小程序或QQ','聊天室：使用图形用户界面，能实现一个聊天室中多人聊天，可以两人私聊，可以发送文件。','QQ:实现类似QQ用户注册、登录、聊天等功能。使用socket通信',3),('00133','20210036','智能交通信号优化算法研究','该课题旨在研究并优化城市交通信号控制算法，提高交通流畅度和能源利用效率。','要求学生熟悉交通流理论，具备算法设计和分析经验，熟悉仿真工具的使用。',5),('00134','20210009','区块链与物联网融合技术研究','本课题旨在研究区块链技术与物联网的融合应用，实现设备安全互信与数据可信传输。','要求学生熟悉区块链和物联网技术，具备相关应用开发经验，熟悉智能合约的编写。',4),('00135','20210019','智能化工业生产调度系统设计','该课题旨在设计智能化工业生产调度系统，结合大数据分析和物联网技术，提高生产效率。','要求学生熟悉大数据分析和物联网技术，具备工业生产调度系统开发经验，熟悉相关标准与规范。',5),('00136','20210028','基于深度学习的恶意代码检测研究','本课题旨在研究深度学习技术在恶意代码检测领域的应用，提高恶意代码检测的准确性。','要求学生具备深度学习基础知识，熟悉计算机安全和恶意代码分析方法，具有良好的编程能力。',6),('00137','20210014','智能化金融风险预警系统设计','该课题旨在设计智能化金融风险预警系统，结合大数据分析和机器学习技术，提高风险识别水平。','要求学生熟悉大数据分析和机器学习技术，具备金融领域相关知识，熟悉相关金融规则与法规。',4),('00138','20210033','虚拟现实（VR）在教育中的应用研究','本课题旨在研究虚拟现实技术在教育领域的应用，设计并实现创新的教学体验。','要求学生熟悉虚拟现实技术，具备教育技术应用开发经验，熟悉相关教育理论与方法。',5),('00139','20210007','智能化电梯管理系统设计','该课题旨在设计智能化电梯管理系统，结合物联网技术和大数据分析，提高电梯运行效率。','要求学生熟悉物联网技术和大数据分析，具备嵌入式系统开发经验，了解电梯运行原理。',4),('00140','20210024','基于区块链的数字版权保护技术研究','本课题旨在研究区块链技术在数字版权保护中的应用，设计安全可靠的数字版权保护方案。','要求学生熟悉区块链技术，了解数字版权相关法规，具备相关应用开发经验。',5),('00161','20210006','网络多人抢答竞赛','类似于学习强国APP上有一个功能是知识抢答竞赛。','参赛者可以有4位选手，比赛开始，系统将题目发放给选手。如果有人答对则加20分，打错不加分另给一道题目。当有选手率先答完5题，则获得胜利。请实现一个PC版地多人抢答竞赛。要求比赛时，每位选手都能看到比赛进度（每个人地得分数）。 ',2);
/*!40000 ALTER TABLE `topic` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `check_topic` BEFORE INSERT ON `topic` FOR EACH ROW BEGIN
    -- 检查课题号长度
    IF LENGTH(NEW.topic_id) > 5
    THEN
        SIGNAL SQLSTATE '45015' SET MESSAGE_TEXT = '题目长度不能大于5！';
    END IF;

    -- 检查课题最大人数
    IF NEW.max_num <= 0
    THEN
        SIGNAL SQLSTATE '45016' SET MESSAGE_TEXT = '最大选题人数不能小于1！';
    END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `check_topic_update` BEFORE UPDATE ON `topic` FOR EACH ROW BEGIN
    -- 检查课题号长度
    IF LENGTH(NEW.topic_id) > 5
    THEN
        SIGNAL SQLSTATE '45033' SET MESSAGE_TEXT = '题目长度不能大于5！';
    END IF;

    -- 检查课题最大人数
    IF NEW.max_num <= 0
    THEN
        SIGNAL SQLSTATE '45034' SET MESSAGE_TEXT = '最大选题人数不能小于1！';
    END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `topic_after_update` AFTER UPDATE ON `topic` FOR EACH ROW BEGIN
    DECLARE curr_num INT;
    -- 查询当前题目已批准的选题数
    SELECT COUNT(*) INTO curr_num FROM Selection WHERE topic_id = NEW.topic_id AND status = '通过';
    -- 查询最大选题人数
    SELECT max_num INTO @max_num FROM Topic WHERE topic_id = NEW.topic_id;
    -- 如果已批准的选题数大于最大选题数，弹出错误信息，将插入操作回滚
    IF curr_num > @max_num THEN
        SIGNAL SQLSTATE '45036' SET MESSAGE_TEXT =
                '该话题选题人数已满！最大选题人数不能再减小！';
    END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Final view structure for view `account_adm`
--

/*!50001 DROP VIEW IF EXISTS `account_adm`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `account_adm` AS select `admin`.`ad_id` AS `ad_id`,`admin`.`password` AS `password` from `admin` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `account_stu`
--

/*!50001 DROP VIEW IF EXISTS `account_stu`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `account_stu` AS select `student`.`stu_id` AS `stu_id`,`student`.`password` AS `password` from `student` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `account_tea`
--

/*!50001 DROP VIEW IF EXISTS `account_tea`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `account_tea` AS select `teacher`.`tea_id` AS `tea_id`,`teacher`.`password` AS `password` from `teacher` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `info_stu`
--

/*!50001 DROP VIEW IF EXISTS `info_stu`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `info_stu` AS select `student`.`stu_id` AS `stu_id`,`student`.`name` AS `name`,`student`.`gender` AS `gender`,`student`.`age` AS `age`,`student`.`email` AS `email`,`student`.`phone_number` AS `phone_number`,`student`.`department` AS `department`,`student`.`major` AS `major` from `student` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `info_teacher`
--

/*!50001 DROP VIEW IF EXISTS `info_teacher`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `info_teacher` AS select `teacher`.`tea_id` AS `tea_id`,`teacher`.`name` AS `name`,`teacher`.`gender` AS `gender`,`teacher`.`age` AS `age`,`teacher`.`email` AS `email`,`teacher`.`phone_number` AS `phone_number`,`teacher`.`department` AS `department`,`teacher`.`title` AS `title` from `teacher` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `info_topic`
--

/*!50001 DROP VIEW IF EXISTS `info_topic`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `info_topic` AS select `topic`.`topic_id` AS `topic_id`,`topic`.`topic_title` AS `topic_title`,`teacher`.`tea_id` AS `tea_id`,`teacher`.`name` AS `teacher_name`,(`topic`.`max_num` - (select count(0) from `selection` where ((`topic`.`topic_id` = `selection`.`topic_id`) and (`selection`.`status` = '通过')))) AS `remaining_count`,`topic`.`max_num` AS `max_num`,`topic`.`description` AS `description`,`topic`.`requirement` AS `requirement` from (`topic` join `teacher`) where (`topic`.`tea_id` = `teacher`.`tea_id`) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `stu_select`
--

/*!50001 DROP VIEW IF EXISTS `stu_select`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `stu_select` AS select `student`.`stu_id` AS `stu_id`,`student`.`name` AS `stu_name`,`teacher`.`tea_id` AS `tea_id`,`teacher`.`name` AS `tea_name`,`topic`.`topic_title` AS `topic_title`,`topic`.`topic_id` AS `topic_id`,`selection`.`status` AS `status` from (((`student` join `teacher`) join `topic`) join `selection`) where ((`topic`.`tea_id` = `teacher`.`tea_id`) and (`selection`.`stu_id` = `student`.`stu_id`) and (`selection`.`topic_id` = `topic`.`topic_id`)) order by `student`.`stu_id` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `stu_teacher`
--

/*!50001 DROP VIEW IF EXISTS `stu_teacher`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `stu_teacher` AS select `teacher`.`tea_id` AS `tea_id`,`student`.`stu_id` AS `stu_id`,`student`.`name` AS `name`,`student`.`gender` AS `gender`,`student`.`age` AS `age`,`student`.`department` AS `department`,`student`.`major` AS `major`,`student`.`phone_number` AS `phone_number`,`student`.`email` AS `email` from (((`student` join `selection`) join `topic`) join `teacher`) where ((`topic`.`tea_id` = `teacher`.`tea_id`) and (`student`.`stu_id` = `selection`.`stu_id`) and (`topic`.`topic_id` = `selection`.`topic_id`) and (`selection`.`status` = '通过')) order by `student`.`stu_id` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `stu_unselect`
--

/*!50001 DROP VIEW IF EXISTS `stu_unselect`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `stu_unselect` AS select `student`.`stu_id` AS `stu_id`,`student`.`name` AS `name`,`student`.`department` AS `department`,`student`.`major` AS `major`,`student`.`phone_number` AS `phone_number` from `student` where `student`.`stu_id` in (select `selection`.`stu_id` from `selection` where (`selection`.`status` <> '不通过')) is false order by `student`.`stu_id` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-01-17 15:55:39
