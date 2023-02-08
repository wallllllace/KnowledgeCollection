const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = {
    entry: './src/index.js',
    output: {
        filename: '[name].bundle.[hash:6].js',
        path: path.resolve(__dirname, 'dist'),
        clean: true
    },
    mode: 'development', // 设置mode环境
    module: {
        rules: [
            {
                test: /\.(js|jsx)$/i,
                exclude: /(node_modules|bower_components)/,
                use: {
                    loader: 'babel-loader',
                    options: {
                        presets: ['@babel/preset-env', '@babel/preset-react'],
                    },
                }
            },
            {
                test: /\.(css|scss|sass)$/i,
                use: ['style-loader', 'css-loader','sass-loader']
            },
            {
                test: /\.(png|svg|jpg|jpeg|gif)$/i,
                type:'asset/resource'
            }
        ]
    },
    plugins: [
        new HtmlWebpackPlugin({
            title: 'MyHybrid',
            minify: {
                removeAttributeQuotes: true, // 移除属性的引号
                removeComments: true, // 移除HTML中的注释
                collapseWhitespace: true, // 删除空白符与换行符
                minifyCSS: true // 压缩内联css
            },
            templateParameters: (compilation, assets, assetTags, options) => {
                console.log(arguments);
                return {
                    title: "MyHybrid",
                    rootId: "app"
                };
            },
            inject: true,
            hash: true,
            filename: "index.html",
            template: "./public/index.html"
        }),
    ]
};