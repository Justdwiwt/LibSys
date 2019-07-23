SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for book
-- ----------------------------
DROP TABLE IF EXISTS `book`;
CREATE TABLE `book`
(
    `id`       int(11) NOT NULL AUTO_INCREMENT,
    `bookname` varchar(30) DEFAULT NULL,
    `author`   varchar(30) DEFAULT NULL,
    `isbn`     varchar(30) DEFAULT NULL,
    `pub`      varchar(30) DEFAULT NULL,
    `inDate`   date        DEFAULT NULL,
    `total`    int(11)     DEFAULT NULL,
    `left`     int(11)     DEFAULT NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB
  AUTO_INCREMENT = 7
  DEFAULT CHARSET = utf8;

-- ----------------------------
-- Table structure for borrowrecord
-- ----------------------------
DROP TABLE IF EXISTS `borrowrecord`;
CREATE TABLE `borrowrecord`
(
    `id`               int(11) NOT NULL AUTO_INCREMENT,
    `bookid`           int(11) DEFAULT NULL,
    `userid`           int(11) DEFAULT NULL,
    `borrowdate`       date    DEFAULT NULL,
    `shouldreturndate` date    DEFAULT NULL,
    `returndate`       date    DEFAULT NULL,
    `continue`         int(11) DEFAULT NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB
  AUTO_INCREMENT = 6
  DEFAULT CHARSET = utf8;

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user`
(
    `id`       int(11) NOT NULL AUTO_INCREMENT,
    `name`     varchar(20) DEFAULT NULL,
    `password` varchar(20) DEFAULT NULL,
    `usertype` int(11)     DEFAULT NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB
  AUTO_INCREMENT = 4
  DEFAULT CHARSET = utf8;
