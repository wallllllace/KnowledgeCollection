import React from 'react';
import Home from '../pages/Home';
import About from '../pages/About';
import Me from '../pages/Me';
import Other from '../pages/Other';

export const navs = [
    {
        name: "首页",
        key: "main",
        path: "/home",
        component: Home
    },
    {
        name: "项目管理",
        key: "projects",
        path: "/projects",
        component: About
    },
    {
        name: "数据中心",
        key: "dataCenter",
        path: "/dataCenter",
        component: Me
    },
    {
        name: "文档中心",
        key: "document",
        path: "/document",
        component: Other
    },
    {
        name: "XConsole",
        key: "xconsole",
        path: "/xconsole",
        component: <h1>XConsole</h1>
    },
    {
        name: "管理员",
        key: "admin",
        path: "/admin",
        component: <h1>admin</h1>
    }
];

export const app_admin_navs = navs;