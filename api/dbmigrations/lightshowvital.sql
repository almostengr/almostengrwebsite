create table if not exists lightshowdisplay
(
    lightshowdisplayid int not null AUTO_INCREMENT,
    windchill varchar(25),
    nwstemp varchar(25),
    cputemp varchar(100) not null,
    title varchar(250) not null,
    artist varchar(250),
    album varchar(250),
    createdTime TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    createdIpAddress VARCHAR(255) NOT NULL,
    PRIMARY KEY (`lightshowdisplayid`)
);

insert into lightshowdisplay
(windchill, nwstemp, cputemp, title, artist, album, createdIpAddress)
values
("None", "32F 0C", "212F 100C", "Testing Title", "Testing Artist", "Testing Album", "localhost")
;