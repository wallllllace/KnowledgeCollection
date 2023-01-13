const path = require('path');
const HtmlWebpackPligin = require('html-webpack-plugin');
const { title } = require('process');

module.exports = {
//   entry: './src/index.js',
    entry: {
        index: './src/index.js',
        print: './src/print.js',
    },    
  output: {
    // filename: 'main.js',
    // filename: 'bundle.js',
    filename: '[name].bundle.js',
    path: path.resolve(__dirname, 'dist'),
    clean: true
  },
  module: {
    rules: [
        {
            test: /\.css$/i,
            use: ['style-loader', 'css-loader'],
        },
        {
            test: /\.(png|svg|jpg|jpeg|gif)$/i,
            type: 'asset/resource',
        },
        {
            test: /\.(woff|woff2|eot|ttf|otf)$/i
        }
    ],
  },
  plugins: [
    new HtmlWebpackPligin({
        title: '管理输出',
    }),
  ]
};