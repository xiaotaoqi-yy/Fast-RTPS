/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef LatencyTest_H
#define LatencyTest_H

#include <thrift/TDispatchProcessor.h>
#include "Latency_types.h"



class LatencyTestIf {
 public:
  virtual ~LatencyTestIf() {}
  virtual void latency(std::string& _return, const std::string& param) = 0;
};

class LatencyTestIfFactory {
 public:
  typedef LatencyTestIf Handler;

  virtual ~LatencyTestIfFactory() {}

  virtual LatencyTestIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(LatencyTestIf* /* handler */) = 0;
};

class LatencyTestIfSingletonFactory : virtual public LatencyTestIfFactory {
 public:
  LatencyTestIfSingletonFactory(const boost::shared_ptr<LatencyTestIf>& iface) : iface_(iface) {}
  virtual ~LatencyTestIfSingletonFactory() {}

  virtual LatencyTestIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(LatencyTestIf* /* handler */) {}

 protected:
  boost::shared_ptr<LatencyTestIf> iface_;
};

class LatencyTestNull : virtual public LatencyTestIf {
 public:
  virtual ~LatencyTestNull() {}
  void latency(std::string& /* _return */, const std::string& /* param */) {
    return;
  }
};

typedef struct _LatencyTest_latency_args__isset {
  _LatencyTest_latency_args__isset() : param(false) {}
  bool param;
} _LatencyTest_latency_args__isset;

class LatencyTest_latency_args {
 public:

  LatencyTest_latency_args() : param() {
  }

  virtual ~LatencyTest_latency_args() throw() {}

  std::string param;

  _LatencyTest_latency_args__isset __isset;

  void __set_param(const std::string& val) {
    param = val;
  }

  bool operator == (const LatencyTest_latency_args & rhs) const
  {
    if (!(param == rhs.param))
      return false;
    return true;
  }
  bool operator != (const LatencyTest_latency_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LatencyTest_latency_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LatencyTest_latency_pargs {
 public:


  virtual ~LatencyTest_latency_pargs() throw() {}

  const std::string* param;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LatencyTest_latency_result__isset {
  _LatencyTest_latency_result__isset() : success(false) {}
  bool success;
} _LatencyTest_latency_result__isset;

class LatencyTest_latency_result {
 public:

  LatencyTest_latency_result() : success() {
  }

  virtual ~LatencyTest_latency_result() throw() {}

  std::string success;

  _LatencyTest_latency_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const LatencyTest_latency_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const LatencyTest_latency_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LatencyTest_latency_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LatencyTest_latency_presult__isset {
  _LatencyTest_latency_presult__isset() : success(false) {}
  bool success;
} _LatencyTest_latency_presult__isset;

class LatencyTest_latency_presult {
 public:


  virtual ~LatencyTest_latency_presult() throw() {}

  std::string* success;

  _LatencyTest_latency_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class LatencyTestClient : virtual public LatencyTestIf {
 public:
  LatencyTestClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  LatencyTestClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void latency(std::string& _return, const std::string& param);
  void send_latency(const std::string& param);
  void recv_latency(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class LatencyTestProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<LatencyTestIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (LatencyTestProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_latency(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  LatencyTestProcessor(boost::shared_ptr<LatencyTestIf> iface) :
    iface_(iface) {
    processMap_["latency"] = &LatencyTestProcessor::process_latency;
  }

  virtual ~LatencyTestProcessor() {}
};

class LatencyTestProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  LatencyTestProcessorFactory(const ::boost::shared_ptr< LatencyTestIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< LatencyTestIfFactory > handlerFactory_;
};

class LatencyTestMultiface : virtual public LatencyTestIf {
 public:
  LatencyTestMultiface(std::vector<boost::shared_ptr<LatencyTestIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~LatencyTestMultiface() {}
 protected:
  std::vector<boost::shared_ptr<LatencyTestIf> > ifaces_;
  LatencyTestMultiface() {}
  void add(boost::shared_ptr<LatencyTestIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void latency(std::string& _return, const std::string& param) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->latency(_return, param);
    }
    ifaces_[i]->latency(_return, param);
    return;
  }

};



#endif
