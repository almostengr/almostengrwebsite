CREATE TABLE IF NOT EXISTS `songsetting` (
    `settingid` INT NOT NULL AUTO_INCREMENT ,
    `identifier` VARCHAR(255) NOT NULL ,
    `value` VARCHAR(255) NOT NULL ,
    `modified` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ,
    PRIMARY KEY (`settingid`)
); 

INSERT INTO `songsetting` (`settingid`, `identifier`, `value`, `modified`) VALUES (NULL, 'currentsong', 'testingsong', current_timestamp()); 