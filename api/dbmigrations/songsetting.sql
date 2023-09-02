CREATE TABLE IF NOT EXISTS `songsetting` (
    `settingid` INT NOT NULL AUTO_INCREMENT ,
    `identifier` VARCHAR(255) NOT NULL ,
    `value` VARCHAR(255) NOT NULL ,
    `modified` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ,
    PRIMARY KEY (`settingid`)
); 

INSERT INTO `songsetting` (`settingid`, `identifier`, `value`, `modified`) 
select NULL, 'currentsong', '', current_timestamp() from dual
where not exists (select * from songsetting where identifier = 'currentsong');

insert into songsetting (settingid, identifier, songsetting.value, modified)
select null, 'cputempc', 0, current_timestamp() from dual
where not exists (select * from songsetting where identifier = 'cputempc');

insert into songsetting (settingid, identifier, songsetting.value, modified)
select null, 'outdoortempc', 0, current_timestamp() from dual
where not exists (select * from songsetting where identifier = 'outdoortempc');

insert into songsetting (settingid, identifier, songsetting.value, modified)
select null, 'nwstempc', 0, current_timestamp() from dual
where not exists (select * from songsetting where identifier = 'nwstempc');
