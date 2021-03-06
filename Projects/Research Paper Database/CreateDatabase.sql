create database sampledb;
use sampledb;

create table Paper (
	PaperID int auto_increment,
    title varchar(63),
    abstract varchar(255),
    pdf varchar(127),
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
	ReportID int auto_increment,
    commentDescription varchar(255),
    recommendation char(1),
    ReportDate date,
    MemberID int,
    PaperID int,
    primary key (ReportID),
    unique (PaperID, MemberID),
    foreign key (MemberID) references PCMember (MemberID),
    foreign key (PaperID) references Paper(PaperID)
    );
    
create table AuthorPaper (
	PaperID int,
    AuthorID int,
    contribution int,
    primary key (PaperID, AuthorID),
    foreign key (PaperID) references Paper (PaperID),
    foreign key (AuthorID) references Author (AuthorID)
    );
    
    
use sampledb;

insert into author (AuthorName, affiliation, email)
values ('Fotouhi', 'Wayne State', 'farshadfotouhi@wayne.edu'),
('Lu', 'Wayne State', 'shiyonglu@wayne.edu'),
('Sanderson', 'Brigham Young', 'bsanderson@brighamyoung.edu'),
('Kaku', 'City College of New York', 'michiokaku@ccny.edu'),
('Tyson', 'Columbia', 'neiltyson@columbia.edu'),
('Nye', 'MIT', 'billnye@mit.edu'),
('Sagan', 'Harvard', 'carlsagan@harvard.edu'),
('Obama', 'Harvard', 'barackobama@harvard.edu'),
('Tan', 'Wayne State', 'lisatan@wayne.edu'),
('Goel', 'Wayne State', 'ngoel@wayne.edu');

insert into pcmember (MemberName, email)
values ('Adam', 'adam@gmail.com'),
('Matt', 'matt@yahoo.com'),
('John', 'john@aol.com'),
('Justin', 'justin@compuserve.com'),
('Richard', 'richard@ymail.com'),
('Lisa', 'lisa@att.net'),
('Laura', 'laura@comcast.net'),
('Nicole', 'nicole@verizon.com'),
('Job', 'job@job314.com'),
('Austin', 'austin@netzero.com');

insert into Paper (title, abstract, pdf)
values ('Computer Architecture', 'Computer Architecture for the Future', 'computerarchitecture.pdf'),
('Artificial Intelligence', 'Methods to advance arificial intelligence', 'ai.pdf'),
('Data Security', 'Increasing data security', 'ds.pdf'),
('Computers and Robots', 'Link between computers and robots', 'candr.pdf'),
('Open Source Software', 'How to design open source software', 'opers.pdf'),
('Machine Learning', 'How machine learning will change computers', 'machine.pdf'),
('Quantum Computing', 'The future of computing', 'quantum.pdf'),
('Search Algorithms', 'How to enhance search algorithms', 'search.pdf'),
('Computers in Education', 'Using computers to educate young minds', 'cine.pdf'),
('Data Management', 'Improving data management', 'data.pdf'),
('Computer Design', 'A look into CPU design','computerdesign.pdf');

insert into Report (commentDescription, recommendation, ReportDate, MemberID, PaperID)
values ('Very nice', 'A', '2018-11-13', 3, 4),
('Terrible', 'R', '2018-11-12',2,5),
('Best paper ever', 'A', '2018-11-10',4,4),
('Bad logic', 'R', '2018-12-01',1,5),
('Horrific', 'R', '2018-11-13',1,1),
('Fantastic', 'A', '2018-11-12',6,4),
('Worst paper ever', 'R', '2018-11-14',4,1),
('Best thing I ever read', 'A', '2018-11-09',5,1),
('Not worth my time', 'R', '2018-11-01', 7, 5),
('Worthy of the hype', 'A', '2018-11-09', 9, 2),
('Best paper I reviewed all year', 'A', '2018-11-10',8,2),
('Over hyped and convoluted', 'R', '2018-11-08',3,2),
('Absolute garbage','R','2018-11-13',3,11),
('Best thing I read today', 'A', '2018-11-01',8,11),
('The tree that was made to use this paper is weeping somewhere', 'R','2018-12-01',2,11);

insert into authorpaper (paperid, authorid, contribution)
values (1,3,1),
(1,2,2),
(2,4,1),
(2,7,2),
(1,1,3),
(3,5,1),
(4,9,1),
(4,1,2),
(4,3,3),
(5,8,1),
(6,10,1),
(6,6,2),
(7,4,1),
(7,10,2),
(8,1,1),
(8,3,2),
(9,7,1),
(9,1,2),
(10,2,1),
(11,1,1);




    
