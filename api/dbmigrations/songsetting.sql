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
select null, 'nwstempc', 0, current_timestamp() from dual
where not exists (select * from songsetting where identifier = 'nwstempc');

insert into songsetting (settingid, identifier, songsetting.value, modified)
select null, 'queuecount', 0, current_timestamp() from dual
where not exists (select * from songsetting where identifier = 'queuecount');

insert into songsetting (settingid, identifier, songsetting.value, modified)
select null, 'seasonplayedcount', 0, current_timestamp() from dual
where not exists (select * from songsetting where identifier = 'seasonplayedcount');

insert into songsetting (settingid, identifier, songsetting.value, modified)
select null, 'nightlyplayedcount', 0, current_timestamp() from dual
where not exists (select * from songsetting where identifier = 'nightlyplayedcount');

insert into songsetting (settingid, identifier, songsetting.value, modified)
select null, 'windchill', 0, current_timestamp() from dual
where not exists (select * from songsetting where identifier = 'windchill');

drop table if exists songsetting;
