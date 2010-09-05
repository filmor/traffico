VERSION='0.0'
APPNAME='traffico'

def set_options(opt):
    opt.tool_options('compiler_cxx')
    opt.tool_options('boost')

def configure(conf):
    for i in """-O3 -Wall -g3 -fomit-frame-pointer -march=prescott -std=c++0x
    -Wno-deprecated""".split():
        conf.env.append_value('CXXFLAGS', i)

    conf.check_tool('compiler_cxx')
    conf.check_tool('boost')

    conf.check_boost(lib='graph', min_version='1.42',
            uselib_store='BOOST')

def build(bld):
    bld.add_subdirs('src')

