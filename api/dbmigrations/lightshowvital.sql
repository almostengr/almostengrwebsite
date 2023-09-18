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
