import React from 'react';
import Home from '../pages/home';
import Projects from '../pages/projects';
import DataCenter from '../pages/dataCenter';
import Document from '../pages/document';
import Xconsole from '../pages/xconsole';
import Admin from '../pages/admin';

export const navs = [
    {
        name: "首页",
        key: "main",
        path: "/",
        component: Home
    },
    {
        name: "项目管理",
        key: "projects",
        path: "/projects",
        component: Projects
    },
    {
        name: "数据中心",
        key: "dataCenter",
        path: "/dataCenter",
        component: DataCenter
    },
    {
        name: "文档中心",
        key: "document",
        path: "/document",
        component: Document
    },
    {
        name: "XConsole",
        key: "xconsole",
        path: "/xconsole",
        component: Xconsole
    },
    {
        name: "管理员",
        key: "admin",
        path: "/admin",
        component: Admin
    }
];

export const app_admin_navs = navs;