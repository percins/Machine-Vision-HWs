clear;
clc;
%% Reading the information of the corresponding points from the text file provided:
file=fopen('points.txt','r');
content=fscanf(file,'%d %d %d %d',[4 inf])';
fclose(file);
d1=content(:,1:2);
d2=content(:,3:4);
%% Forming the matrices representing the linear equations:
npoints=length(d1);
D=zeros(npoints*2,6);
for i=1:npoints
   D(i*2-1,1:2)=d2(i,:);
   D(i*2-1,3)=1;
   D(i*2,4:5)=d2(i,:);
   D(i*2,6)=1;
end
d=reshape(d1.',[npoints*2,1]);
%% Finding the solution for the linear equations
h=D\d;
%% Explicitly writing the Homography Map
H=[h(1:3).';h(4:6).'; 0 0 1]
%% Writing the homography map to a file to forward to the process continuing in c++:
file2=fopen('manualH.txt','w');
fprintf(file2,"%f ",H.');
fclose(file2);

