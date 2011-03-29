global root_dir home_dir host

fs = filesep;
root_dir = [fileparts(which('startup')) fs];
home_dir = [fileparts(fileparts(root_dir)) fs];

addpath([root_dir]);
%addpath([root_dir  'Cfiles']);
addpath([root_dir '..\..\Mfiles\StructDlg']);
addpath([root_dir '..\Analysis_Mfiles\']);

% addpath('D:\users\Alon\Papers\VisFlip\figs');
addpath([root_dir(1:3) 'users\Manipulandum']);