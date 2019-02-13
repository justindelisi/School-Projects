create database sampledb;
use sampledb;

create table Paper (
	PaperID int auto_increment,
    title varChar(63),
    abstract varChar(255),
    pdf varChar(127),
    primary key (PaperID)
    );

create table Author (
	AuthorID int auto_increment,
    AuthorName varchar(63),
    affiliation varchar(127),
    email varchar(127),
    primary key (AuthorID)
    );

create table PCMember (
	MemberID int auto_increment,
    MemberName varchar(255) NOT NULL,
    email varchar(255),
    primary key (MemberID)
    );

create table Report (
	ReportID int NOT NULL auto_increment,
    commentDescription varchar(255),
    recommendation char(1),
    ReportDate date,
    MemberID int,
    PaperID int,
    unique(PaperID, MemberID),
    primary key (ReportID), 
    foreign key (MemberID) references PCMember,
    foreign key (PaperID) references Paper
    );
    
create table AuthorPaper (
	PaperID int,
    AuthorID int,
    contribution int,
    primary key (PaperID, AuthorID),
    foreign key (PaperID) references Paper,
    foreign key (AuthorID) references Author
    );
    

    

